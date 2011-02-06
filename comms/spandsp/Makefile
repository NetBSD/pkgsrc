# $NetBSD: Makefile,v 1.1.1.1 2011/02/06 08:32:06 jnemeth Exp $
#

DISTNAME=	spandsp-0.0.6pre18
CATEGORIES=	comms
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc_users@NetBSD.org
HOMEPAGE=	http://www.soft-switch.org/downloads/spandsp/
COMMENT=	Library of DSP functions for telephony
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

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
