# $NetBSD: options.mk,v 1.5 2007/02/22 19:27:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.groff
PKG_SUPPORTED_OPTIONS=	groff-docs x11
PKG_SUGGESTED_OPTIONS=	groff-docs x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgroff-docs)
DEPENDS+=		netpbm>=10.0:../../graphics/netpbm
DEPENDS+=		psutils>=1.17:../../print/psutils
USE_TOOLS+=		gs:run
PLIST_SRC+=		PLIST.docs
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-appresdir=${PREFIX}/lib/X11/app-defaults
PLIST_SRC+=		PLIST.x11
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Interix"
CONFIGURE_ENV+=		X_EXTRA_LIBS=-lXext
.endif
.else
CONFIGURE_ARGS+=	--without-x
.endif
