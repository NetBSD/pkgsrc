# $NetBSD: Makefile,v 1.1 2023/03/02 04:45:57 charlotte Exp $

DISTNAME=	cromagrally-3.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}
DISTFILES+=	${DEFAULT_DISTFILES} ${POMME}

POMME=		88a3e4625b00f63cde90aae5ce383d85c83cc5a8.tar.gz
SITES.${POMME}=	${MASTER_SITE_GITHUB:=jorio/}Pomme/archive/

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://pangeasoft.net/cromag/
COMMENT=	Source port of Cro-Mag Rally from Pangea Software
LICENSE=	cc-by-nc-sa-v4.0-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

WRKSRC=		${WRKDIR}/CroMagRally-${GITHUB_TAG}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/cromagrally/Data

post-extract:
	${RM} -rf ${WRKSRC}/extern/Pomme
	${LN} -sf ${WRKDIR}/Pomme-${POMME:S/.tar.gz//} ${WRKSRC}/extern/Pomme

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/cromagrally.template > ${WRKDIR}/cromagrally

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cromagrally ${DESTDIR}${PREFIX}/bin/cromagrally
	${INSTALL_PROGRAM} ${WRKSRC}/CroMagRally ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/cromagrally/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
