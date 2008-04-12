# $NetBSD: options.mk,v 1.2 2008/04/12 22:42:59 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdesdk
PKG_SUPPORTED_OPTIONS=	svn

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		svn

.if !empty(PKG_OPTIONS:Msvn)
.include "../../devel/subversion-base/buildlink3.mk"
CONFIGURE_ARGS+=	--with-apr-config=${BUILDLINK_PREFIX.apr}/bin/apr-config
CONFIGURE_ARGS+=	--with-apu-config=${BUILDLINK_PREFIX.apr}/bin/apu-config
CONFIGURE_ARGS+=	--with-svn-include=${BUILDLINK_PREFIX.subversion-base}/include/subversion-1
CONFIGURE_ARGS+=	--with-svn-lib=${BUILDLINK_PREFIX.subversion-base}/lib
PLIST.svn=		yes
.else
CONFIGURE_ARGS+=	--disable-subversion
.endif
