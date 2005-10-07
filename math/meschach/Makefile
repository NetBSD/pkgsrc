# $NetBSD: Makefile,v 1.12 2005/10/07 12:32:33 rillig Exp $

DISTNAME=		mesch12b
PKGNAME=		meschach-1.2b
CATEGORIES=		math
MASTER_SITES=		http://www.math.uiowa.edu/~dstewart/meschach/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.math.uiowa.edu/~dstewart/meschach/
COMMENT=		Library of C Routines for Matrix Computations

WRKSRC=			${WRKDIR}
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-all
MAKEFILE=		makefile

pre-patch:
	${CP} ${FILESDIR}/makefile.in ${WRKSRC}

post-patch:
	${SED} -e 's:@PREFIX@:'${PREFIX}':g' ${FILESDIR}/makefile.test 	\
		> ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/meschach
	cd ${WRKSRC} && ${INSTALL_DATA} err.h machine.h matlab.h 	\
		matrix.h meminfo.h sparse.h zmatrix.h iter.h matrix2.h 	\
		oldnames.h sparse2.h zmatrix2.h ${PREFIX}/include/meschach/
	${INSTALL_DATA_DIR} ${PREFIX}/share/meschach
	${INSTALL_DATA_DIR} ${PREFIX}/share/meschach/tests
	cd ${WRKSRC} && ${INSTALL_DATA} torture.c sptort.c ztorture.c 	\
		memtort.c itertort.c mfuntort.c iotort.c 		\
		${PREFIX}/share/meschach/tests/
	${INSTALL_DATA} ${WRKSRC}/Makefile ${PREFIX}/share/meschach/tests
	cd ${WRKSRC} && ${INSTALL_DATA} README ./DOC/* 			\
		${PREFIX}/share/meschach/
	${INSTALL_DATA} ${WRKSRC}/copyright ${PREFIX}/share/meschach
	cd ${WRKSRC} && ${INSTALL_DATA} tutadv.c tutorial.c		\
		${PREFIX}/share/meschach/

.include "../../mk/bsd.pkg.mk"
