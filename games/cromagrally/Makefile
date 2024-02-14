# $NetBSD: Makefile,v 1.5 2024/02/14 19:04:05 charlotte Exp $

DISTNAME=	cromagrally-3.0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://pangeasoft.net/cromag/
COMMENT=	Source port of Cro-Mag Rally from Pangea Software
LICENSE=	cc-by-nc-sa-v4.0-license

GITHUB_SUBMODULES=	\
	jorio Pomme ef94150e2dcec522e3099f4d03a4e8f2639f7232 extern/Pomme

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

WRKSRC=		${WRKDIR}/CroMagRally-${GITHUB_TAG}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/cromagrally/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/cromagrally.template > ${WRKDIR}/cromagrally

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cromagrally ${DESTDIR}${PREFIX}/bin/cromagrally
	${INSTALL_PROGRAM} ${WRKSRC}/CroMagRally ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/cromagrally/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
