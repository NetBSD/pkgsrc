# $NetBSD: Makefile,v 1.2 2023/03/10 01:56:51 charlotte Exp $

DISTNAME=	nanosaur2-2.1.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://jorio.itch.io/nanosaur2
COMMENT=	Source port of Nanosaur 2: Hatchling from Pangea Software
LICENSE=	cc-by-nc-sa-v4.0-license

GITHUB_SUBMODULES=	\
	jorio Pomme 6e4ea042ba9e7e525d3930e45662be15605153c4 extern/Pomme

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

WRKSRC=		${WRKDIR}/Nanosaur2-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/nanosaur2/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/nanosaur2.template > ${WRKDIR}/nanosaur2

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/nanosaur2 ${DESTDIR}${PREFIX}/bin/nanosaur2
	${INSTALL_PROGRAM} ${WRKSRC}/Nanosaur2 ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/nanosaur2/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
