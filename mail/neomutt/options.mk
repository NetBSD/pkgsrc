# $NetBSD: options.mk,v 1.22 2024/05/06 08:27:53 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.neomutt
PKG_OPTIONS_REQUIRED_GROUPS=	display
PKG_OPTIONS_GROUP.display=	curses ncurses ncursesw
PKG_SUPPORTED_OPTIONS=		tokyocabinet lmdb
PKG_SUPPORTED_OPTIONS+=		debug gpgme gssapi ssl smime sasl
PKG_SUPPORTED_OPTIONS+=		notmuch lua
PKG_SUGGESTED_OPTIONS=		gpgme gssapi ncursesw sasl smime ssl
PKG_SUGGESTED_OPTIONS+=		tokyocabinet notmuch

.include "../../mk/bsd.options.mk"

###
### GSSAPI
###
CONFIGURE_ENV+=		ac_cv_path_KRB5CFGPATH=${KRB5_CONFIG}
.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gss=${KRB5BASE}
.endif

###
### ncurses
###
.if !empty(PKG_OPTIONS:Mncurses)
USE_NCURSES=		yes
.  include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
.endif

###
### SASLv2
###
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
.endif

### curses
###
.if !empty(PKG_OPTIONS:Mcurses)
.  include "../../mk/curses.buildlink3.mk"
OPSYSVARS+=			BUILDLINK_PASSTHRU_DIRS
BUILDLINK_PASSTHRU_DIRS.SunOS+=	/usr/xpg4
CONFIGURE_ARGS.SunOS+=		--with-ncurses=/usr/xpg4
LDFLAGS.SunOS+=			-L/usr/xpg4/lib${LIBABISUFFIX}
LDFLAGS.SunOS+=			${COMPILER_RPATH_FLAG}/usr/xpg4/lib${LIBABISUFFIX}
.endif

###
### ncursesw
###
.if !empty(PKG_OPTIONS:Mncursesw)
.  include "../../devel/ncurses/buildlink3.mk"
.else
SUBST_CLASSES+=		curse
SUBST_MESSAGE.curse=	Fixing mutt to avoid ncursesw
SUBST_STAGE.curse=	pre-configure
SUBST_FILES.curse=	configure.ac
SUBST_SED.curse=	-e 's,for lib in ncurses ncursesw,for lib in ncurses,'
.endif

###
### SSL
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

###
### S/MIME
###
PLIST_VARS+=		smime
.if !empty(PKG_OPTIONS:Msmime)
USE_TOOLS+=		perl:run
REPLACE_PERL+=		contrib/smime_keys
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--smime
PLIST.smime=		yes
.else
CONFIGURE_ARGS+=	--disable-smime
.endif

###
### Header cache
###
.if !empty(PKG_OPTIONS:Mlmdb)
.include "../../databases/lmdb/buildlink3.mk"
CONFIGURE_ARGS+=	--lmdb
CONFIGURE_ARGS+=	--disable-gdbm
CONFIGURE_ARGS+=	--disable-bdb
.elif !empty(PKG_OPTIONS:Mtokyocabinet)
.include "../../databases/tokyocabinet/buildlink3.mk"
CONFIGURE_ARGS+=	--tokyocabinet
CONFIGURE_ARGS+=	--disable-gdbm
CONFIGURE_ARGS+=	--disable-bdb
.else
BDB_ACCEPTED=		db4 db5
BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--bdb
CONFIGURE_ARGS+=	--disable-gdbm
# BDB_INCLUDE_DIR_ and BDB_LIB_DIR don't have to be particularly accurate
# since the real -I and -L flags are added by buildlink already.
CONFIGURE_ENV+=		BDB_INCLUDE_DIR=${BDBBASE}/include
CONFIGURE_ENV+=		BDB_LIB_DIR=${BDBBASE}/lib
CONFIGURE_ENV+=		BDB_LIB=${BDB_LIBS:S/^-l//:M*:Q}
.endif

###
### Enable debugging support
###
.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS+=	-g
.endif

###
### gpgme support
###
.if !empty(PKG_OPTIONS:Mgpgme)
CONFIGURE_ARGS+=	--gpgme
.  include "../../security/gpgme/buildlink3.mk"
.endif

###
### notmuch support
###
.if !empty(PKG_OPTIONS:Mnotmuch)
.include "../../mail/notmuch/buildlink3.mk"
CONFIGURE_ARGS+=	--notmuch
.else
CONFIGURE_ARGS+=	--disable-notmuch
.endif

###
### lua support
###
.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
.include "../../lang/lua/tool.mk"
CONFIGURE_ARGS+=	--lua
CONFIGURE_ARGS+=	--with-lua=${BUILDLINK_PREFIX.lua}
.else
CONFIGURE_ARGS+=	--disable-lua
.endif
