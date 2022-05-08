# $NetBSD: Makefile,v 1.11 2022/05/08 12:06:34 triaxx Exp $

GFXVER=		7.1
MSXVER=		0.4.2
SFXVER=		1.0.3
PKGNAME=	openttd-data-${GFXVER}
CATEGORIES=	games x11
MASTER_SITES=	https://proxy.binaries.openttd.org/
DISTFILES=	opengfx-${GFXVER}-all.zip
DISTFILES+=	openmsx-${MSXVER}-all.zip
DISTFILES+=	opensfx-${SFXVER}-all.zip
EXTRACT_SUFX=	.zip

SITES.opengfx-${GFXVER}-all.zip=	${MASTER_SITES:Q}opengfx-releases/${GFXVER}/
SITES.openmsx-${MSXVER}-all.zip=	${MASTER_SITES:Q}openmsx-releases/${MSXVER}/
SITES.opensfx-${SFXVER}-all.zip=	${MASTER_SITES:Q}opensfx-releases/${SFXVER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openttd.org/
COMMENT=	Free data files for OpenTTD
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	share/openttd/data
INSTALLATION_DIRS+=	share/openttd/gm

USE_TOOLS+=	tar

post-extract:
	cd ${WRKDIR} && tar xvf opengfx-${GFXVER}.tar
	cd ${WRKDIR} && tar xvf openmsx-${MSXVER}.tar
	cd ${WRKDIR} && tar xvf opensfx-${SFXVER}.tar

do-install:
	${INSTALL_DATA} ${WRKDIR}/opengfx-${GFXVER}/*.grf \
		${DESTDIR}${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKDIR}/opengfx-${GFXVER}/*.obg \
		${DESTDIR}${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKDIR}/openmsx-${MSXVER}/*.mid \
		${DESTDIR}${PREFIX}/share/openttd/gm
	${INSTALL_DATA} ${WRKDIR}/openmsx-${MSXVER}/*.obm \
		${DESTDIR}${PREFIX}/share/openttd/gm
	${INSTALL_DATA} ${WRKDIR}/opensfx-${SFXVER}/*.cat \
		${DESTDIR}${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKDIR}/opensfx-${SFXVER}/*.obs \
		${DESTDIR}${PREFIX}/share/openttd/data

.include "../../mk/bsd.pkg.mk"
