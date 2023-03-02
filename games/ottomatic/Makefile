# $NetBSD: Makefile,v 1.1 2023/03/02 04:14:15 charlotte Exp $

DISTNAME=	ottomatic-4.0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}
DISTFILES+=	${DEFAULT_DISTFILES} ${POMME}

POMME=		ad9cc177d2187f67bd00cb6cf2b3045ef91c577b.tar.gz
SITES.${POMME}=	${MASTER_SITE_GITHUB:=jorio/}Pomme/archive/

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://pangeasoft.net/otto/
COMMENT=	Pangea Software's Otto Matic
LICENSE=	cc-by-nc-sa-v4.0-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

WRKSRC=			${WRKDIR}/OttoMatic-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/ottomatic/Data

post-extract:
	${RM} -rf ${WRKSRC}/extern/Pomme
	${LN} -sf ${WRKDIR}/Pomme-${POMME:S/.tar.gz//} ${WRKSRC}/extern/Pomme

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/ottomatic.template > ${WRKDIR}/ottomatic

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ottomatic ${DESTDIR}${PREFIX}/bin/ottomatic
	${INSTALL_PROGRAM} ${WRKSRC}/OttoMatic ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/ottomatic/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
