# $NetBSD: Makefile,v 1.1 2023/02/15 02:21:37 charlotte Exp $

DISTNAME=	nanosaur-1.4.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTFILES+=	${DEFAULT_DISTFILES} ${POMME}

POMME=		fd1cd2cf81a2d39a4e47e76485860a87f0bf33f6.tar.gz
SITES.${POMME}=	${MASTER_SITE_GITHUB:=jorio/}Pomme/archive/

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.pangeasoft.net/nano/index.html
COMMENT=	Source port of Nanosaur from Pangea Software
LICENSE=	cc-by-nc-sa-v4.0-license

WRKSRC=		${WRKDIR}/Nanosaur-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/nanosaur/Data

post-extract:
	${RM} -rf ${WRKSRC}/extern/Pomme
	${LN} -sf ${WRKDIR}/Pomme-${POMME:S/.tar.gz//} ${WRKSRC}/extern/Pomme

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/nanosaur.template > ${WRKDIR}/nanosaur

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/nanosaur ${DESTDIR}${PREFIX}/bin/nanosaur
	${INSTALL_PROGRAM} ${WRKSRC}/Nanosaur ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/nanosaur/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
