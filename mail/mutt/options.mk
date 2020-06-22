# $NetBSD: options.mk,v 1.35 2020/06/22 06:24:15 wiz Exp $

# Global and legacy options

PKG_OPTIONS_VAR=		PKG_OPTIONS.mutt
PKG_OPTIONS_REQUIRED_GROUPS=	display
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.display=	curses wide-curses slang
PKG_OPTIONS_GROUP.ssl=		gnutls openssl
PKG_SUPPORTED_OPTIONS=		debug gpgme idn smime sasl
# TODO: add kyoto cabinet and lmdb backend options for header cache
PKG_SUPPORTED_OPTIONS+=		mutt-hcache mutt-compressed-mbox tokyocabinet mutt-smtp
PKG_SUPPORTED_OPTIONS+=		gssapi
PKG_SUGGESTED_OPTIONS=		curses gpgme mutt-hcache mutt-smtp smime openssl
PKG_SUGGESTED_OPTIONS+=		gssapi mutt-compressed-mbox sasl
# remove after 2019Q1
PKG_OPTIONS_LEGACY_OPTS+=	ncurses:curses ncursesw:wide-curses
PKG_OPTIONS_LEGACY_OPTS+=	ssl:openssl

# Must be at the top; some other buildlink files indirectly
# include bdb.buildlink3.mk.
BDB_ACCEPTED=		db4 db5

.include "../../mk/bsd.options.mk"

###
### GSSAPI
###
CONFIGURE_ENV+=		ac_cv_path_KRB5CFGPATH=${KRB5_CONFIG}
.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gss=${KRB5BASE}
.endif

### curses
###
.if !empty(PKG_OPTIONS:Mcurses) || !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.curses}
.  if ${CURSES_TYPE:U} == curses
OPSYSVARS+=			BUILDLINK_PASSTHRU_DIRS
BUILDLINK_PASSTHRU_DIRS.SunOS+=	/usr/xpg4
CONFIGURE_ARGS.SunOS+=		--with-curses=/usr/xpg4
LDFLAGS.SunOS+=			-L/usr/xpg4/lib${LIBABISUFFIX}
LDFLAGS.SunOS+=			${COMPILER_RPATH_FLAG}/usr/xpg4/lib${LIBABISUFFIX}
.  endif
.endif

###
### GnuTLS
###
.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnutls=${BUILDLINK_PREFIX.gnutls}
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

###
### Slang
###
.if !empty(PKG_OPTIONS:Mslang)
.  include "../../devel/libslang2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang2}
.endif

###
### SASLv2
###
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
.endif

###
### SSL
###
.if !empty(PKG_OPTIONS:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### S/MIME
###
PLIST_VARS+=		smime
.if !empty(PKG_OPTIONS:Msmime)
USE_TOOLS+=		perl:run
REPLACE_PERL+=		*.pl */*.pl
.  if empty(PKG_OPTIONS:Mopenssl) && empty(PKG_OPTIONS:Mgnutls)
PKG_FAIL_REASON+=	"The smime option requires the openssl or gnutls options."
.  endif
CONFIGURE_ARGS+=	--enable-smime
PLIST.smime=		yes
.else
CONFIGURE_ARGS+=	--disable-smime
.endif

###
### Header cache
###
.if !empty(PKG_OPTIONS:Mmutt-hcache)
.  if !empty(PKG_OPTIONS:Mtokyocabinet)
.    include "../../databases/tokyocabinet/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hcache
CONFIGURE_ARGS+=	--enable-tokyocabinet
CONFIGURE_ARGS+=	--without-gdbm
CONFIGURE_ARGS+=	--without-bdb
.  else
BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.    include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hcache
CONFIGURE_ARGS+=	--without-gdbm
# BDB_INCLUDE_DIR_ and BDB_LIB_DIR don't have to be particularly accurate
# since the real -I and -L flags are added by buildlink already.
CONFIGURE_ENV+=		BDB_INCLUDE_DIR=${BDBBASE}/include
CONFIGURE_ENV+=		BDB_LIB_DIR=${BDBBASE}/lib
CONFIGURE_ENV+=		BDB_LIB=${BDB_LIBS:S/^-l//:M*:Q}
.  endif
.else
CONFIGURE_ARGS+=	--disable-hcache
.endif

###
### Compressed mail boxes
###
.if !empty(PKG_OPTIONS:Mmutt-compressed-mbox)
CONFIGURE_ARGS+=	--enable-compressed
.else
CONFIGURE_ARGS+=	--disable-compressed
.endif

###
### Internal SMTP relay support
###
.if !empty(PKG_OPTIONS:Mmutt-smtp)
CONFIGURE_ARGS+=	--enable-smtp
.else
CONFIGURE_ARGS+=	--disable-smtp
.endif

###
### Internationalized Domain Names
###
.if !empty(PKG_OPTIONS:Midn)
.  include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-idn=${BUILDLINK_PREFIX.libidn}
.else
CONFIGURE_ARGS+=	--with-idn=no
.endif

###
### Enable debugging support
###
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
CFLAGS+=		-g
.endif

###
### gpgme support
###
.if !empty(PKG_OPTIONS:Mgpgme)
.  include "../../security/gpgme/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--with-gpgme-prefix=${BUILDLINK_PREFIX.gpgme}
.else
CONFIGURE_ARGS+=	--disable-gpgme
.endif
