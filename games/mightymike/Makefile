# $NetBSD: Makefile,v 1.1 2023/06/28 23:40:48 charlotte Exp $

DISTNAME=	mightymike-3.0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://jorio.itch.io/mightymike
COMMENT=	Pangea Software's Mighty Mike (Power Pete) for modern systems
LICENSE=	cc-by-nc-sa-v4.0-license

GITHUB_SUBMODULES=	\
	jorio Pomme d57c28e205462e51063e787f9ebddaadff592f1e extern/Pomme

WRKSRC=	${WRKDIR}/MightyMike-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/mightymike/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/mightymike.template > ${WRKDIR}/mightymike

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mightymike ${DESTDIR}${PREFIX}/bin/mightymike
	${INSTALL_PROGRAM} ${WRKSRC}/MightyMike ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/mightymike/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
