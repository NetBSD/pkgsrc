# $NetBSD: Makefile,v 1.1.1.1 2004/07/30 13:49:40 wiz Exp $
#

DISTNAME=		ltm-0.30
CATEGORIES=		math
MASTER_SITES=		http://math.libtomcrypt.org/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://math.libtomcrypt.org/
COMMENT=		Number theoretic multiple-precision integer library

WRKSRC=			${WRKDIR}/libtommath-0.30
USE_BUILDLINK3=		yes
MAKEFILE=		makefile
ALL_TARGET=		default

do-install:
	${INSTALL_DATA} ${WRKSRC}/tommath.h ${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libtommath.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/bn.pdf ${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/poster.pdf ${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/tommath.pdf ${PREFIX}/share/doc/ltm

.include "../../mk/bsd.pkg.mk"
