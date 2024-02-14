# $NetBSD: Makefile,v 1.1 2024/02/14 19:47:13 charlotte Exp $

DISTNAME=	bugdom2-4.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://jorio.itch.io/bugdom2
COMMENT=	Source port of Bugdom 2 from Pangea Software
LICENSE=	cc-by-nc-sa-v4.0-license

GITHUB_SUBMODULES=	\
	jorio Pomme c6a38eab19a11847024a13f9b3e2af0c2d908c3e extern/Pomme

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

WRKSRC=		${WRKDIR}/Bugdom2-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/bugdom2/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/bugdom2.template > ${WRKDIR}/bugdom2

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bugdom2 ${DESTDIR}${PREFIX}/bin/bugdom2
	${INSTALL_PROGRAM} ${WRKSRC}/Bugdom2 ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/bugdom2/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
