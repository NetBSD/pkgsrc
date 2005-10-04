# $NetBSD: options.mk,v 1.10 2005/10/04 15:37:32 tonio Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.mutt
PKG_SUPPORTED_OPTIONS=	slang ncurses ssl sasl mutt-hcache idn
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Slang and ncurses
###
.if !empty(PKG_OPTIONS:Mslang)
.  include "../../devel/libslang/buildlink3.mk"
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang}
.else
.  if !empty(PKG_OPTIONS:Mncurses)
USE_NCURSES=		yes
.  endif
.  include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncurses}
.endif

###
### SASLv2
###
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
.endif

###
### SSL
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### Header cache
###
.if !empty(PKG_OPTIONS:Mmutt-hcache)
BDB_ACCEPTED=		db4
.  include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hcache
CONFIGURE_ARGS+=	--without-gdbm
#
# BDB_INCLUDE_DIR_ and BDB_LIB_DIR don't have to be particularly accurate
# since the real -I and -L flags are added by buildlink already.
#
CONFIGURE_ENV+=		BDB_INCLUDE_DIR=${BDBBASE}/include
CONFIGURE_ENV+=		BDB_LIB_DIR=${BDBBASE}/lib
CONFIGURE_ENV+=		BDB_LIB=${BDB_LIBS:S/^-l//}
.else
CONFIGURE_ARGS+=	--disable-hcache
.endif

###
### Internationalized Domain Names
###
.if !empty(PKG_OPTIONS:Midn)
.  include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=  --with-idn=${BUILDLINK_PREFIX.libidn}
.else
CONFIGURE_ARGS+=  --disable-idn
.endif
