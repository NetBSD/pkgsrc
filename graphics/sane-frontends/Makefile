# $NetBSD: Makefile,v 1.19 2004/11/05 13:34:10 adam Exp $

.include "../sane-backends/Makefile.common"

DISTNAME=       sane-frontends-${SANE_VERSION}
SANE_MICRO=	13

COMMENT=	Frontends for access to scanners, digitals camera, frame grabbers etc

BUILDLINK_DEPENDS.sane=	sane-backends>=${SANE_VERSION}

USE_X11BASE=	YES

.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
