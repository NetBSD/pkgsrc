# $NetBSD: options.mk,v 1.20 2016/02/25 15:00:51 jperkin Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.mutt
PKG_OPTIONS_REQUIRED_GROUPS=	display
PKG_OPTIONS_GROUP.display=	slang ncurses ncursesw curses
PKG_SUPPORTED_OPTIONS=	debug gpgme idn ssl smime sasl
PKG_SUPPORTED_OPTIONS+=	mutt-hcache tokyocabinet mutt-smtp
PKG_SUPPORTED_OPTIONS+=	mutt-compressed-mbox
PKG_SUPPORTED_OPTIONS+=	mutt-sidebar
PKG_SUGGESTED_OPTIONS=	curses gpgme mutt-hcache mutt-smtp smime ssl
# un-comment out the following lines whenever updating distinfo
# and patches are up-to-date
#PKG_SUGGESTED_OPTIONS+=	mutt-compressed-mbox
#PKG_SUGGESTED_OPTIONS+=	mutt-sidebar

.include "../../mk/bsd.options.mk"

###
### Slang
###
.if !empty(PKG_OPTIONS:Mslang)
.  include "../../devel/libslang/buildlink3.mk"
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang}
.endif

###
### ncurses
###
.if !empty(PKG_OPTIONS:Mncurses)
USE_NCURSES=		yes
.  include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncurses}
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
CONFIGURE_ARGS.SunOS+=		--with-curses=/usr/xpg4
LDFLAGS.SunOS+=			-L/usr/xpg4/lib${LIBABISUFFIX}
LDFLAGS.SunOS+=			${COMPILER_RPATH_FLAG}/usr/xpg4/lib${LIBABISUFFIX}
.endif

###
### ncursesw
###
.if !empty(PKG_OPTIONS:Mncursesw)
.  include "../../devel/ncursesw/buildlink3.mk"
.else
SUBST_CLASSES+=		curse
SUBST_MESSAGE.curse=	Fixing mutt to avoid ncursesw
SUBST_STAGE.curse=	post-patch
SUBST_FILES.curse=	configure
SUBST_SED.curse=	-e 's,for lib in ncurses ncursesw,for lib in ncurses,'
.endif

###
### SSL
###
.if !empty(PKG_OPTIONS:Mssl)
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
.  include "../../security/openssl/buildlink3.mk"
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
.  include "../../databases/tokyocabinet/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hcache
CONFIGURE_ARGS+=	--enable-tokyocabinet
CONFIGURE_ARGS+=	--without-gdbm
CONFIGURE_ARGS+=	--without-bdb
.  else
BDB_ACCEPTED=		db4 db5
BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.  include "../../mk/bdb.buildlink3.mk"
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
PLIST_VARS+=		compressed_mbox
.if !empty(PKG_OPTIONS:Mmutt-compressed-mbox)
PLIST.compressed_mbox=	yes
PATCH_SITES+=		http://mutt.org.ua/download/${PKGNAME_NOREV}/
PATCHFILES+=		patch-${PKGVERSION_NOREV}.rr.compressed.gz
PATCH_DIST_STRIP=	-p1
CONFIGURE_ARGS+=	--enable-compressed
SUBST_CLASSES+=		compress
SUBST_MESSAGE.compress=	Patch Makefile.in to avoid autoreconf for compress
SUBST_STAGE.compress=	post-patch
SUBST_FILES.compress=	Makefile.in
SUBST_SED.compress=	-e 's,^mutt_SOURCES = ,mutt_SOURCES = compress.c ,'
SUBST_SED.compress+=	-e 's,^EXTRA_DIST = ,EXTRA_DIST = compress.h ,'
SUBST_SED.compress+=	-e 's,^mutt_OBJECTS = ,mutt_OBJECTS = compress.o ,'
# add xsltproc to be able to regenerate the documentation
BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
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
### Sidebar support
###
.if !empty(PKG_OPTIONS:Mmutt-sidebar)
# http://www.lunar-linux.org/mutt-sidebar/
PATCH_SITES+=		http://lunar-linux.org/~tchan/mutt/
PATCHFILES+=		patch-1.5.23.sidebar.20140412.txt
PATCH_DIST_STRIP=	-p1
PATCH_FUZZ_FACTOR=	-F1
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
CFLAGS+= -g
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
