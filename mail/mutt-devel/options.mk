# $NetBSD: options.mk,v 1.24 2007/04/21 18:27:21 tonio Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.mutt
PKG_OPTIONS_REQUIRED_GROUPS=	display
PKG_OPTIONS_GROUP.display=	slang ncurses ncursesw curses
PKG_SUPPORTED_OPTIONS=	ssl smime sasl mutt-hcache idn mutt-smtp debug
PKG_SUGGESTED_OPTIONS=	ssl smime curses

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
.if !empty(PKG_OPTIONS:Msmime)
USE_TOOLS+=		perl:run
REPLACE_PERL+=		*.pl */*.pl
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-smime
PLIST_SUBST+=		WITHSMIME=''
.else
CONFIGURE_ARGS+=	--disable-smime
PLIST_SUBST+=		WITHSMIME='@comment '
.endif

###
### Header cache
###
.if !empty(PKG_OPTIONS:Mmutt-hcache)
.  include "../../databases/db4/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hcache
CONFIGURE_ARGS+=	--without-gdbm
#
# BDB_INCLUDE_DIR_ and BDB_LIB_DIR don't have to be particularly accurate
# since the real -I and -L flags are added by buildlink already.
#
CONFIGURE_ENV+=		BDB_INCLUDE_DIR=${BUILDLINK_PREFIX.db4}/include
CONFIGURE_ENV+=		BDB_LIB_DIR=${BUILDLINK_PREFIX.db4}/lib
CONFIGURE_ENV+=		BDB_LIB=${BUILDLINK_LDADD.db4:S/^-l//:Q}
.else
CONFIGURE_ARGS+=	--disable-hcache
.endif

###
### Internal SMTP relay support
###
.if !empty(PKG_OPTIONS:Mmutt-smtp)
CONFIGURE_ARGS+=       --enable-smtp
.else
CONFIGURE_ARGS+=       --disable-smtp
.endif

###
### Internationalized Domain Names
###
.if !empty(PKG_OPTIONS:Midn)
.  include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-idn=${BUILDLINK_PREFIX.libidn}
.else
CONFIGURE_ARGS+=	--disable-idn
.endif

###
### Enable debugging support
###
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
CFLAGS+= -g
.endif
