# $NetBSD: Makefile,v 1.4 2012/10/03 11:24:44 asau Exp $
#

DISTNAME=	spandsp-0.0.6pre18
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.soft-switch.org/downloads/spandsp/
COMMENT=	Library of DSP functions for telephony
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/spandsp-0.0.6
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	spandsp.pc.in

INSTALLATION_DIRS=	share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/DueDiligence ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
