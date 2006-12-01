# $NetBSD: Makefile,v 1.31 2006/12/01 15:44:23 adam Exp $

.include "../../graphics/sane-backends/Makefile.common"

DISTNAME=	sane-frontends-${SANE_VERSION}
SANE_MICRO=	14

COMMENT=	Frontends for access to scanners, digitals camera, frame grabbers etc

BUILDLINK_API_DEPENDS.sane+=	sane-backends>=${SANE_VERSION}

USE_TOOLS+=	pkg-config
USE_X11BASE=	YES

PKG_OPTIONS_VAR=	PKG_OPTIONS.sane-frontends
PKG_SUPPORTED_OPTIONS=	gimp
PKG_SUGGESTED_OPTIONS=	gimp
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgimp)
.include "../../graphics/gimp/buildlink3.mk"
.endif
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
