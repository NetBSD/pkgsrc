# $NetBSD: Makefile,v 1.16 2004/03/29 22:31:58 snj Exp $

.include "../sane-backends/Makefile.common"

DISTNAME=       sane-frontends-${SANE_VERSION}
PKGREVISION=	2

COMMENT=	Frontends for access to scanners, digitals camera, frame grabbers etc

BUILDLINK_DEPENDS.sane=	sane-backends>=${SANE_VERSION}

USE_X11BASE=	YES

.include "../../graphics/sane-backends/buildlink2.mk"
.include "../../graphics/gimp1-base/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
