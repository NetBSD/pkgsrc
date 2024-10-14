# $NetBSD: options.mk,v 1.14 2024/10/14 06:45:59 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.groff
PKG_SUPPORTED_OPTIONS=	groff-docs x11
PKG_SUGGESTED_OPTIONS=	groff-docs x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgroff-docs)
DEPENDS+=		netpbm>=10.0:../../graphics/netpbm
DEPENDS+=		${PYPKGPREFIX}-pspdfutils-[0-9]*:../../print/py-pspdfutils
USE_TOOLS+=		gs:run
PLIST_SRC+=		PLIST.docs

.include "../../lang/python/pyversion.mk"
.else
CONFIGURE_ENV+=		with_doc=no
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-appresdir=${PREFIX}/lib/X11/app-defaults
PLIST_SRC+=		PLIST.x11
.include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ENV.Interix+=	X_EXTRA_LIBS=-lXext
.else
CONFIGURE_ARGS+=	--without-x
.endif
