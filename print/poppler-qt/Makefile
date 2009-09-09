# $NetBSD: Makefile,v 1.20 2009/09/09 19:57:06 drochner Exp $
#

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-qt-${POPPLER_VERS}

COMMENT=		PDF rendering library (QT wrapper)
MAINTAINER=		reed@reedmedia.net

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-cairo-output
CONFIGURE_ARGS+=	--disable-splash-output
CONFIGURE_ARGS+=	--enable-poppler-qt
CONFIGURE_ARGS+=	--disable-gtk-test
CONFIGURE_ARGS+=	--disable-utils
CONFIGURE_ARGS+=	--disable-cms

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt.pc.in

INCS=-I. -I.. -I../poppler `pkg-config poppler --cflags` -I${QTDIR}/include

INSTALLATION_DIRS+=	lib include/poppler lib/pkgconfig

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
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/qt/libpoppler-qt.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/qt/poppler-qt.h ${DESTDIR}${PREFIX}/include/poppler
	${INSTALL_DATA} ${WRKSRC}/qt/poppler-page-transition.h \
		${DESTDIR}${PREFIX}/include/poppler
	${INSTALL_DATA} ${WRKSRC}/qt/poppler-link-qt3.h \
		${DESTDIR}${PREFIX}/include/poppler
	${INSTALL_DATA} ${WRKSRC}/poppler-qt.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

BUILDLINK_API_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
