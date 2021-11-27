# $NetBSD: options.mk,v 1.1 2021/11/27 12:33:20 pho Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.gkrellsun
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+=	gmake msgfmt
MAKE_FLAGS+=	enable_nls=1
MAKE_FLAGS+=	LOCALEDIR="${PREFIX}/${PKGLOCALEDIR}/locale"
MAKE_FLAGS+=	INSTALL_PREFIX="${DESTDIR}"
.endif
