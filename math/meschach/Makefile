# $NetBSD: Makefile,v 1.1.1.1 2000/12/05 00:06:42 jtb Exp $

DISTNAME=		mesch12b
PKGNAME=		meschach-1.2b
CATEGORIES=		math
MASTER_SITES=		ftp://ftpmaths.anu.edu.au/pub/meschach/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		ftp://ftpmaths.anu.edu/pub/meschach/meschach.html

WRKSRC=			${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=		YES
WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	"--with-all"

pre-patch:
	@${CP} ${FILESDIR}/makefile.in ${WRKSRC}

post-patch:
	@${SED} -e 's:%%PREFIX%%:'${PREFIX}':g' < ${FILESDIR}/makefile.test \
	> ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/meschach
	@for i in err.h machine.h matlab.h matrix.h meminfo.h sparse.h \
	zmatrix.h iter.h matrix2.h oldnames.h sparse2.h zmatrix2.h ; do \
	${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/include/meschach ; done
	${INSTALL_DATA_DIR} ${PREFIX}/share/meschach
	${INSTALL_DATA_DIR} ${PREFIX}/share/meschach/tests
	@for t in torture.c sptort.c ztorture.c memtort.c itertort.c \
	mfuntort.c iotort.c ; do \
	${INSTALL_DATA} ${WRKSRC}/$$t ${PREFIX}/share/meschach/tests ; done
	${INSTALL_DATA} ${WRKSRC}/Makefile ${PREFIX}/share/meschach/tests
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/DOC/* ${PREFIX}/share/meschach
	${INSTALL_DATA} ${WRKSRC}/copyright ${PREFIX}/share/meschach
	@for e in tutadv.c tutorial.c ; do \
	${INSTALL_DATA} ${WRKSRC}/$$e ${PREFIX}/share/meschach ; done

.include "../../mk/bsd.pkg.mk"
