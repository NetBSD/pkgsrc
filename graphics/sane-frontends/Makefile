# $NetBSD: Makefile,v 1.11 2002/12/16 18:06:13 tron Exp $

.include "../sane-backends/Makefile.common"

DISTNAME=       sane-frontends-${SANE_VERSION}

COMMENT=	Frontends for access to scanners, digitals camera, frame grabbers etc

BUILDLINK_DEPENDS.sane=	sane-backends-${SANE_VERSION}

USE_X11BASE=	YES

.include "../../graphics/sane-backends/buildlink2.mk"
.include "../../graphics/gimp-base/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
