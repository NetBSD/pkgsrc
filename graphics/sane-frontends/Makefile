# $NetBSD: Makefile,v 1.20 2005/11/25 21:23:15 wiz Exp $

.include "../sane-backends/Makefile.common"

DISTNAME=       sane-frontends-${SANE_VERSION}
PKGREVISION=	1
SANE_MICRO=	13

COMMENT=	Frontends for access to scanners, digitals camera, frame grabbers etc

BUILDLINK_DEPENDS.sane=	sane-backends>=${SANE_VERSION}

USE_X11BASE=	YES

.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
