# $NetBSD: Makefile,v 1.132 2016/02/16 04:21:40 dbj Exp $

DISTNAME=	octave-4.0.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=octave/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.octave.org/
COMMENT=	High-level language, intended for numerical computations
LICENSE=	gnu-gpl-v3

# These BUILD_DEPENDS are only needed if we need to rebuild the documentation
#BUILD_DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
#BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
#BUILD_DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
#BUILD_DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
#BUILD_DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
#TOOL_DEPENDS+=	gtexinfo>=5.1:../../devel/gtexinfo

DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gsed gmake:run perl pkg-config bison
GNU_CONFIGURE=		yes

GCC_REQD+=		3.0
USE_LANGUAGES=		c c++ fortran77

# needed for loading of shared objects such as those in the
# octave-forge package or user written ones compiled with mkoctfile
CONFIGURE_ARGS+=	--enable-dl
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-shared

#CONFIGURE_ARGS+=	--without-opengl
#CONFIGURE_ARGS+=	--with-framework-opengl=no
CONFIGURE_ARGS+=	--disable-java
# use this to bypass qt5 portability issues:
#CONFIGURE_ARGS+=	CPPFLAGS=-DQT_DISABLE_DEPRECATED_BEFORE=0

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# When __APPLE__ is defined, fltk headers typedef an alternate version of Window
# which conflicts with the one in the X11 headers, so avoid pulling in X11.
CONFIGURE_ARGS+=	--without-x

# The OpenGL framework doesn't have osmesa and the X11 one has header conflicts with the framework
CONFIGURE_ARGS+=	--without-OSMesa
.endif

# We use this to install .oct files so it doesn't strip them.
CONFIGURE_ENV+=		INSTALL_LIB=${INSTALL_LIB:Q}

.include "options.mk"

INFO_FILES=	yes
OCTAVE_DOC=	doc/interpreter/octave.pdf doc/liboctave/liboctave.pdf \
		doc/refcard/refcard-a4.pdf doc/refcard/refcard-legal.pdf \
		doc/refcard/refcard-letter.pdf
INSTALLATION_DIRS+=	share/octave/${PKGVERSION_NOREV}/doc

#CHECK_WRKREF_SKIP+=	share/octave/${PKGVERSION_NOREV}/etc/config.log

TEST_TARGET=	check

#pre-configure:
#	cd ${WRKSRC} && autoconf

SUBST_CLASSES+=			fix-make
SUBST_STAGE.fix-make=		pre-configure
SUBST_MESSAGE.fix-make=		Fixing path to gmake.
SUBST_FILES.fix-make=		scripts/pkg/private/configure_make.m
SUBST_SED.fix-make=		-e 's:@GMAKE@:$(GMAKE):g'

SUBST_CLASSES+=			qt5-pkg-config
SUBST_STAGE.qt5-pkg-config=	pre-configure
SUBST_MESSAGE.qt5-pkg-config=	Updating pkg-config calls for Qt5
SUBST_FILES.qt5-pkg-config=	configure.ac configure
SUBST_SED.qt5-pkg-config=	-e 's,QtCore,Qt5Core,g'
SUBST_SED.qt5-pkg-config+=	-e 's,QtGui,Qt5Widgets,g'
SUBST_SED.qt5-pkg-config+=	-e 's,QtNetwork,Qt5Network,g'
SUBST_SED.qt5-pkg-config+=	-e 's,QtOpenGL,Qt5OpenGL,g'

PREPEND_PATH+=			${QTDIR}/bin

MAKE_ENV+=			V=1

#post-extract:
#	find ${WRKSRC}/doc -type f -name '*.info*' -print | xargs rm -f
#	mkdir ${WRKSRC}/src/pic

post-install:
.for f in ${OCTAVE_DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/octave/${PKGVERSION_NOREV}/doc
.endfor

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/arpack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/libX11/buildlink3.mk"
.endif
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools?=build
.include "../../x11/qt5-qttools/buildlink3.mk"
BUILDLINK_DEPMETHOD.gperf?=build
.include "../../devel/gperf/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
