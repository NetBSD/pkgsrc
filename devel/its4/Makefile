# $NetBSD: Makefile,v 1.21 2017/08/16 20:21:07 wiz Exp $
#

DISTNAME=	its4-1.1.1
CATEGORIES=	devel
MASTER_SITES=	# have to fetch for yourself, or from a NetBSD mirror
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cigital.com/its4/
COMMENT=	Static C/C++ code scanner for potential security problems
LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/its4
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-cpp=${CXX:Q}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/its4
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_LANGUAGES=		c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/its4 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/its4.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/its4
	cd ${WRKSRC} && ${INSTALL_DATA} LICENSE TODO vulns.i4d \
		${DESTDIR}${PREFIX}/share/its4

.include "../../mk/bsd.pkg.mk"
