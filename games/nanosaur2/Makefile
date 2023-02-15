# $NetBSD: Makefile,v 1.1 2023/02/15 03:06:42 charlotte Exp $

DISTNAME=	nanosaur2-2.1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTFILES+=	${DEFAULT_DISTFILES} ${POMME}

POMME=		6e4ea042ba9e7e525d3930e45662be15605153c4.tar.gz
SITES.${POMME}=	${MASTER_SITE_GITHUB:=jorio/}Pomme/archive/

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://jorio.itch.io/nanosaur2
COMMENT=	Source port of Nanosaur 2: Hatchling from Pangea Software
LICENSE=	cc-by-nc-sa-v4.0-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

WRKSRC=		${WRKDIR}/Nanosaur2-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/nanosaur2/Data

post-extract:
	${RM} -rf ${WRKSRC}/extern/Pomme
	${LN} -sf ${WRKDIR}/Pomme-${POMME:S/.tar.gz//} ${WRKSRC}/extern/Pomme

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/nanosaur2.template > ${WRKDIR}/nanosaur2

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/nanosaur2 ${DESTDIR}${PREFIX}/bin/nanosaur2
	${INSTALL_PROGRAM} ${WRKSRC}/Nanosaur2 ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/nanosaur2/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
