# $NetBSD: Makefile,v 1.6 2024/01/30 14:22:02 ryoon Exp $

DISTNAME=	ottomatic-4.0.1
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://pangeasoft.net/otto/
COMMENT=	Pangea Software's Otto Matic
LICENSE=	cc-by-nc-sa-v4.0-license

GITHUB_SUBMODULES=	\
	jorio Pomme ad9cc177d2187f67bd00cb6cf2b3045ef91c577b extern/Pomme

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

USE_CXX_FEATURES+=	has_include

WRKSRC=			${WRKDIR}/OttoMatic-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/ottomatic/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/ottomatic.template > ${WRKDIR}/ottomatic

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ottomatic ${DESTDIR}${PREFIX}/bin/ottomatic
	${INSTALL_PROGRAM} ${WRKSRC}/OttoMatic ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/ottomatic/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
