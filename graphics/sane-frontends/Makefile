# $NetBSD: Makefile,v 1.98 2023/11/12 13:22:17 wiz Exp $

.include "../../graphics/sane-backends/Makefile.common"
MASTER_SITES=	https://gitlab.com/sane-project/frontends/uploads/14e5c5a9205b10bd3df04501852eab28/

DISTNAME=	sane-frontends-${SANE_VERSION}
SANE_MINOR=	0
SANE_MICRO=	14
PKGREVISION=	60

COMMENT=	Frontends for access to scanners, digital cameras, frame grabbers etc

BUILDLINK_API_DEPENDS.sane+=	sane-backends>=${SANE_VERSION}

USE_TOOLS+=	pkg-config

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
