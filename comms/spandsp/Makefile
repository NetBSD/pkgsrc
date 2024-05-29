# $NetBSD: Makefile,v 1.24 2024/05/29 16:31:36 adam Exp $
#

DISTNAME=	spandsp-0.0.6pre21
PKGREVISION=	16
CATEGORIES=	comms
MASTER_SITES=	https://www.soft-switch.org/downloads/spandsp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.soft-switch.org/downloads/spandsp/
COMMENT=	Library of DSP functions for telephony
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/spandsp-0.0.6
GNU_CONFIGURE=	yes
USE_TOOLS+=	gsed pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	spandsp.pc.in

INSTALLATION_DIRS=	share/doc/${PKGBASE}

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/DueDiligence ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
