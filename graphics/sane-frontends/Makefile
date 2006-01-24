# $NetBSD: Makefile,v 1.23 2006/01/24 07:32:17 wiz Exp $

.include "../../graphics/sane-backends/Makefile.common"

DISTNAME=       sane-frontends-${SANE_VERSION}
PKGREVISION=	3
SANE_MICRO=	13

COMMENT=	Frontends for access to scanners, digitals camera, frame grabbers etc

BUILDLINK_DEPENDS.sane+=	sane-backends>=${SANE_VERSION}

USE_X11BASE=	YES

.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
