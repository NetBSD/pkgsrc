# $NetBSD: Makefile,v 1.4 2001/02/27 18:42:05 jtb Exp $

DISTNAME=		mesch12b
PKGNAME=		meschach-1.2b
CATEGORIES=		math
MASTER_SITES=		http://www.math.uiowa.edu/~dstewart/meschach/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.math.uiowa.edu/~dstewart/meschach/
COMMENT=		Library of C Routines for Matrix Computations

WRKSRC=			${WRKDIR}
GNU_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--with-all
MAKEFILE=		makefile

pre-patch:
	${CP} ${FILESDIR}/makefile.in ${WRKSRC}

post-patch:
	${SED} -e 's:@PREFIX@:'${PREFIX}':g' <				\
	${FILESDIR}/makefile.test > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/meschach
	@for f in err.h machine.h matlab.h matrix.h meminfo.h sparse.h	\
	zmatrix.h iter.h matrix2.h oldnames.h sparse2.h zmatrix2.h; do	\
	i="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/include/meschach/";	\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/meschach
	${INSTALL_DATA_DIR} ${PREFIX}/share/meschach/tests
	@for f in torture.c sptort.c ztorture.c memtort.c itertort.c	   \
	mfuntort.c iotort.c; do						   \
	i="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/meschach/tests/"; \
	${ECHO} $$i; $$i;						   \
	done
	${INSTALL_DATA} ${WRKSRC}/Makefile ${PREFIX}/share/meschach/tests
	@for f in ${WRKSRC}/README ${WRKSRC}/DOC/*; do			\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/meschach/";		\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA} ${WRKSRC}/copyright ${PREFIX}/share/meschach
	@for f in tutadv.c tutorial.c; do				\
	i="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/meschach/";	\
	${ECHO} $$i; $$i;						\
	done

.include "../../mk/bsd.pkg.mk"
