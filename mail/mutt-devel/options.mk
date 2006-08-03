# $NetBSD: options.mk,v 1.16 2006/08/03 17:07:04 wiz Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.mutt
PKG_OPTIONS_OPTIONAL_GROUPS=	display
PKG_OPTIONS_GROUP.display=	slang ncurses
PKG_SUPPORTED_OPTIONS=	ssl sasl mutt-hcache idn mutt-compressed-mbox
PKG_SUGGESTED_OPTIONS=	ncurses ssl

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
CONFIGURE_ENV+=		BDB_LIB=${BUILDLINK_LDADD.db4:S/^-l//}
.else
CONFIGURE_ARGS+=	--disable-hcache
.endif

###
### Compressed mail boxes
###
.if !empty(PKG_OPTIONS:Mmutt-compressed-mbox)
PATCH_SITES+=		http://www.spinnaker.de/mutt/compressed/
PATCHFILES+=		patch-1.5.12.rr.compressed.1.gz
PATCH_DIST_STRIP=	-p1
CONFIGURE_ARGS+=	--enable-compressed
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
