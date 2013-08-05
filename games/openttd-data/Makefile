# $NetBSD: Makefile,v 1.4 2013/08/05 19:24:35 adam Exp $

DISTNAME=	openttd-data-0.4.7
CATEGORIES=	games x11
MASTER_SITES=	http://binaries.openttd.org/extra/
DISTFILES=	opengfx-${PKGVERSION_NOREV}-all.zip
DISTFILES+=	openmsx-0.3.1-all.zip
DISTFILES+=	opensfx-0.2.3-all.zip
SITES.opengfx-0.4.7-all.zip=	${MASTER_SITES:Q}/opengfx/${PKGVERSION_NOREV}/
SITES.openmsx-0.3.1-all.zip=	${MASTER_SITES:Q}/openmsx/0.3.1/
SITES.opensfx-0.2.3-all.zip=	${MASTER_SITES:Q}/opensfx/0.2.3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openttd.org/
COMMENT=	Free data files for OpenTTD
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	share/openttd/data
INSTALLATION_DIRS+=	share/openttd/gm

do-install:
	${INSTALL_DATA} ${WRKDIR}/opengfx-${PKGVERSION_NOREV}/*.grf \
		${DESTDIR}${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKDIR}/opengfx-${PKGVERSION_NOREV}/*.obg \
		${DESTDIR}${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKDIR}/openmsx-0.3.1/*.mid \
		${DESTDIR}${PREFIX}/share/openttd/gm
	${INSTALL_DATA} ${WRKDIR}/openmsx-0.3.1/*.obm \
		${DESTDIR}${PREFIX}/share/openttd/gm
	${INSTALL_DATA} ${WRKDIR}/opensfx-0.2.3/*.cat \
		${DESTDIR}${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKDIR}/opensfx-0.2.3/*.obs \
		${DESTDIR}${PREFIX}/share/openttd/data

.include "../../mk/bsd.pkg.mk"
