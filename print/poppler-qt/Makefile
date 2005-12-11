# $NetBSD: Makefile,v 1.1.1.1 2005/12/11 10:07:31 markd Exp $
#

DISTNAME=		poppler-${POPPLER_VERS}
PKGNAME=		poppler-qt-${POPPLER_VERS}
CATEGORIES=		print
MASTER_SITES=		http://poppler.freedesktop.org/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://poppler.freedesktop.org/
COMMENT=		PDF rendering library (QT wrapper)

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt.pc.in

INCS=-I. `pkg-config poppler --cflags` -I${QTDIR}/include
POPPLER_VERS=0.4.2

do-build:
	(cd ${WRKSRC}/qt; \
	${LIBTOOL} --tag=CXX --mode=compile ${CXX} ${CXXFLAGS} ${INCS} -c -o poppler-document.lo poppler-document.cc; \
	${LIBTOOL} --tag=CXX --mode=compile ${CXX} ${CXXFLAGS} ${INCS} -c -o poppler-page.lo poppler-page.cc; \
	${LIBTOOL} --tag=CXX --mode=link ${CXX} ${LDFLAGS} `pkg-config poppler --libs` -L${QTDIR}/lib ${COMPILER_RPATH_FLAG}${QTDIR}/lib -o libpoppler-qt.la -rpath ${PREFIX}/lib poppler-document.lo poppler-page.lo -lqt-mt )
	${SED} -e s:@VERSION@:${POPPLER_VERS}: \
		-e s:@prefix@:${PREFIX}: \
		-e 's:@exec_prefix@:$${prefix}:' \
		-e 's:@libdir@:$${exec_prefix}/lib:' \
		-e 's:@includedir@:$${prefix}/include:' \
	${WRKSRC}/poppler-qt.pc.in > ${WRKSRC}/poppler-qt.pc

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/qt/libpoppler-qt.la ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/qt/poppler-qt.h ${PREFIX}/include/poppler
	${INSTALL_DATA} ${WRKSRC}/poppler-qt.pc ${PREFIX}/lib/pkgconfig

.include "../../print/poppler/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
