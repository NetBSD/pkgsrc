# $NetBSD: Makefile,v 1.19 2012/09/11 23:04:23 asau Exp $

DISTNAME=		mesch12b
PKGNAME=		meschach-1.2b
CATEGORIES=		math
MASTER_SITES=		http://www.math.uiowa.edu/~dstewart/meschach/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.math.uiowa.edu/~dstewart/meschach/
COMMENT=		Library of C Routines for Matrix Computations

WRKSRC=			${WRKDIR}
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-all
MAKE_FILE=		makefile
USE_BSD_MAKEFILE=	yes
MAKE_FLAGS+=		MKPROFILE=yes

INSTALLATION_DIRS=	include/meschach lib share/meschach/tests

BUILDLINK_TRANSFORM+=	rm:-Werror

pre-patch:
	${CP} ${FILESDIR}/makefile.in ${WRKSRC}

post-patch:
	${SED} -e 's:@PREFIX@:'${PREFIX}':g' ${FILESDIR}/makefile.test 	\
		> ${WRKSRC}/Makefile

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} err.h machine.h matlab.h 	\
		matrix.h meminfo.h sparse.h zmatrix.h iter.h matrix2.h 	\
		oldnames.h sparse2.h zmatrix2.h ${DESTDIR}${PREFIX}/include/meschach/
	cd ${WRKSRC} && ${INSTALL_DATA} torture.c sptort.c ztorture.c 	\
		memtort.c itertort.c mfuntort.c iotort.c 		\
		${DESTDIR}${PREFIX}/share/meschach/tests/
	${INSTALL_DATA} ${WRKSRC}/Makefile ${DESTDIR}${PREFIX}/share/meschach/tests
	cd ${WRKSRC} && ${INSTALL_DATA} README ./DOC/* 			\
		${DESTDIR}${PREFIX}/share/meschach/
	${INSTALL_DATA} ${WRKSRC}/copyright ${DESTDIR}${PREFIX}/share/meschach
	cd ${WRKSRC} && ${INSTALL_DATA} tutadv.c tutorial.c		\
		${DESTDIR}${PREFIX}/share/meschach/

.include "../../mk/bsd.pkg.mk"
