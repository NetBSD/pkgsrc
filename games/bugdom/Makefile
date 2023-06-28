# $NetBSD: Makefile,v 1.1 2023/06/28 03:32:41 charlotte Exp $

DISTNAME=	bugdom-1.3.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://pangeasoft.net/bug/
COMMENT=	Pangea Software's Bugdom for modern systems
LICENSE=	cc-by-nc-sa-v4.0-license

GITHUB_SUBMODULES=	\
	jorio Pomme ad9cc177d2187f67bd00cb6cf2b3045ef91c577b extern/Pomme

WRKSRC=		${WRKDIR}/Bugdom-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/bugdom/Data

#post-extract:
#	${RM} -rf ${WRKSRC}/extern/Pomme
#	${LN} -sf ${WRKDIR}/Pomme-${POMME:S/.tar.gz//} ${WRKSRC}/extern/Pomme

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/bugdom.template > ${WRKDIR}/bugdom

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bugdom ${DESTDIR}${PREFIX}/bin/bugdom
	${INSTALL_PROGRAM} ${WRKSRC}/Bugdom ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/bugdom/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
