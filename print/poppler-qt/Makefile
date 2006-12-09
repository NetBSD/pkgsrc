# $NetBSD: Makefile,v 1.13.4.1 2006/12/09 08:38:35 salo Exp $
#

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-qt-${POPPLER_VERS}
PKGREVISION=		1

COMMENT=		PDF rendering library (QT wrapper)

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt.pc.in

INCS=-I. -I.. -I../poppler `pkg-config poppler --cflags` -I${QTDIR}/include

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
	${INSTALL_DATA} ${WRKSRC}/qt/poppler-page-transition.h \
		${PREFIX}/include/poppler
	${INSTALL_DATA} ${WRKSRC}/qt/poppler-link-qt3.h \
		${PREFIX}/include/poppler
	${INSTALL_DATA} ${WRKSRC}/poppler-qt.pc ${PREFIX}/lib/pkgconfig

BUILDLINK_API_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
