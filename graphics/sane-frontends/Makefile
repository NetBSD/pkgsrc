# $NetBSD: Makefile,v 1.29 2006/06/22 10:24:25 joerg Exp $

.include "../../graphics/sane-backends/Makefile.common"

DISTNAME=       sane-frontends-${SANE_VERSION}
PKGREVISION=	6
SANE_MICRO=	13

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
