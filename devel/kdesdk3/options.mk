# $NetBSD: options.mk,v 1.2 2008/04/12 22:42:59 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdesdk
PKG_SUPPORTED_OPTIONS=	svn

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		svn

.if !empty(PKG_OPTIONS:Msvn)
.include "../../devel/subversion-base/buildlink3.mk"
CONFIGURE_ARGS+=	--with-svn-include="${BUILDLINK_PREFIX.subversion-base}/include"
CONFIGURE_ARGS+=	--with-svn-lib="${BUILDLINK_PREFIX.subversion-base}/lib"
PLIST.svn=		yes
.else
CONFIGURE_ARGS+=	--with-subversion=no
.endif
