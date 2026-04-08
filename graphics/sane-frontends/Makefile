# $NetBSD: Makefile,v 1.115 2026/04/08 12:40:58 wiz Exp $

.include "../../graphics/sane-backends/Makefile.common"
MASTER_SITES=	https://gitlab.com/sane-project/frontends/uploads/14e5c5a9205b10bd3df04501852eab28/

DISTNAME=	sane-frontends-${SANE_VERSION}
SANE_MINOR=	0
SANE_MICRO=	14
PKGREVISION=	76

COMMENT=	Frontends for access to scanners, digital cameras, frame grabbers etc

BUILDLINK_API_DEPENDS.sane+=	sane-backends>=${SANE_VERSION}

USE_TOOLS+=	pkg-config

CFLAGS+=	-Wno-implicit-function-declaration

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
