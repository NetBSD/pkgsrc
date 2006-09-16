# $NetBSD: Makefile,v 1.30 2006/09/16 12:20:38 jmmv Exp $

.include "../../graphics/sane-backends/Makefile.common"

DISTNAME=       sane-frontends-${SANE_VERSION}
PKGREVISION=	7
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
