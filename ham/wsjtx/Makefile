# $NetBSD: Makefile,v 1.1 2026/01/19 13:40:53 mef Exp $

DISTNAME=	wsjtx-2.5.4
CATEGORIES=	ham
MASTER_SITES=	https://sourceforge.net/projects/wsjt/files/wsjtx-2.5.4/wsjtx-2.5.4.tgz/
# for 2.6.1
#ASTER_SITES=	https://wsjt.sourceforge.io/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wsjt.sourceforge.io/wsjtx.html
COMMENT=	Weak Signal Communication by Joe Talor (K1JT)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c c++ fortran
USE_TOOLS+=	pkg-config gmake tar
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if ${OPSYS_VERSION} >100000
GCC_REQD+=	14
.  endif
.endif

DEPENDS+=	qt5-qttranslations-[0-9]*:../../x11/qt5-qttranslations

CMAKE_CONFIGURE_ARGS+=	-DNVTT_SHARED=ON
CMAKE_CONFIGURE_ARGS+=	-D CMAKE_INSTALL_PREFIX=${DESTDIR}${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DWSJT_SKIP_MANPAGES=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_PREFIX_PATH=${PREFIX}/qt5
CMAKE_CONFIGURE_ARGS+=	-DWSJT_GENERATE_DOCS=OFF
CMAKE_CONFIGURE_ARGS+=	-DLDFLAGS='-lusb-1.0 -L${PREFIX}/lib -lfftwf'
CMAKE_CONFIGURE_ARGS+=	-DFortran_FLAGS+='-L${PREFIX}/lib'
CMAKE_CONFIGURE_ARGS+=	-DLDFLAGS=-'Wl,-rpath-link=-lusb-1.0 -L${PREFIX}/lib'
CMAKE_CONFIGURE_ARGS+=	-DLIBUSB_CFLAGS='-I ${PREFIX}/include/libusb-1.0 -lusb-1.0 -L${PREFIX}/lib'
CMAKE_CONFIGURE_ARGS+=	-DLIBUSB_LIBS='-Wl,-rpath-link=-lusb-1.0 -L${PREFIX}/lib'
CMAKE_CONFIGURE_ARGS+=	-DLIBS='-Wl,-rpath-link=-lusb-1.0 -L${PREFIX}/lib'
CMAKE_CONFIGURE_ARGS+=	-DQt5Test_DIR=${PREFIX}/qt5/lib/cmake/Qt5Test
#MAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_DO_STRIP=0	# 1.2 MB (jt9)
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug	# 870 kB

#IBUSB_CFLAGS+=	-lusb-1.0 -L${PREFIX}/lib
LDFLAGS+=	${COMPILER_RPATH_FLAG}=-lusb-1.0 -L${PREFIX}/lib
MAKE_ENV+=	AM_LDFLAGS='-lusb-1.0 -L${PREFIX}/lib'

#   27  tar zxvf  ../../distfiles/wsjtx-2.5.4.tgz wsjtx-2.5.4/src/wsjtx.tgz
#   28  mv wsjtx-2.5.4/src/wsjtx.tgz ../../distfiles/wsjtx-src-2.5.4.tgz

pre-patch:
	(cd ${WRKDIR};  \
	tar zxf ${DISTDIR}/${DISTNAME}.tgz wsjtx-2.5.4/src/wsjtx.tgz ; \
	tar zxf wsjtx-2.5.4/src/wsjtx.tgz ;\
	)

WRKSRC=		${WRKDIR}/wsjtx
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PKGDOCDIR}
	${INSTALL_DATA} files/README ${DESTDIR}${PKGDOCDIR}/README.netbsd

# debug only (checking log)
#AKE_JOBS_SAFE=	no

# hamlib-prefix/src/hamlib/configure.ac
SUBST_CLASSES+=		hamlib
SUBST_FILES.hamlib=	hamlib.patch
SUBST_STAGE.hamlib=	pre-configure
SUBST_MESSAGE.hamlib=	fix PREFIX inside patch
SUBST_VARS.hamlib=	PREFIX

# To avoid jt9 to crash
# https://mail-index.netbsd.org/pkgsrc-users/2025/12/23/msg042336.html
NOT_PAX_MPROTECT_SAFE+=	bin/jt9

.include "../../devel/cmake/build.mk"
.include "../../math/fftw/buildlink3.mk"
.if empty(PKG_BUILD_OPTIONS.fftw:Mfftw-fortran)
PKG_FAIL_REASON+=      'You need to set PKG_OPTIONS.fftw+= fftw-fortran, at its compile time.'
.endif

.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
BUILDLINK_API_DEPENDS.hamlib+=	hamlib>=4.1
.include "../../ham/hamlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
