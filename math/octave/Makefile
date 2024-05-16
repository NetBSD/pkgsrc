# $NetBSD: Makefile,v 1.255 2024/05/16 06:15:09 wiz Exp $

DISTNAME=	octave-9.1.0
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=octave/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://octave.org/
COMMENT=	High-level language, intended for numerical computations
LICENSE=	gnu-gpl-v3

# These TOOL_DEPENDS are only needed if we need to rebuild the documentation
#TOOL_DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
#TOOL_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
#TOOL_DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
#TOOL_DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
#TOOL_DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
#TOOL_DEPENDS+=	gtexinfo>=5.1:../../devel/gtexinfo

DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot

USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gsed gmake:run perl pkg-config bison bsdtar:run
USE_TOOLS+=		makeinfo:test
GNU_CONFIGURE=		yes

# needed for loading of shared objects such as those in the
# octave-forge package or user written ones compiled with mkoctfile
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-docs
CONFIGURE_ARGS+=	--with-blas=${BLAS_LIBS:Q}
CONFIGURE_ARGS+=	--with-lapack=${LAPACK_LIBS:Q}
TEST_TARGET=		check

# Provide a full path gfortran in MKOCTFILE for octave-forge
CONFIGURE_ENV+=		MKOCTFILE_F77=${FCPATH}

.include "../../mk/bsd.prefs.mk"

# When __APPLE__ is defined, fltk headers typedef an alternate version of Window
# which conflicts with the one in the X11 headers, so avoid pulling in X11.
CONFIGURE_ARGS.Darwin+=	--without-x

# This is needed on Darwin or we get link failures on modules.
CONFIGURE_ARGS.Darwin+=	--enable-link-all-dependencies

# We use this to install .oct files so it doesn't strip them.
CONFIGURE_ENV+=		INSTALL_LIB=${INSTALL_LIB:Q}

.include "options.mk"

INFO_FILES=	yes
OCTAVE_DOC=	doc/interpreter/octave.pdf doc/liboctave/liboctave.pdf \
		doc/refcard/refcard-a4.pdf doc/refcard/refcard-legal.pdf \
		doc/refcard/refcard-letter.pdf
OCTAVE_INFO=	doc/interpreter/octave.info doc/liboctave/liboctave.info
OCTAVE_MAN=	doc/interpreter/mkoctfile.1 doc/interpreter/octave.1 \
		doc/interpreter/octave-cli.1 doc/interpreter/octave-config.1


INSTALLATION_DIRS+=	share/octave/${PKGVERSION_NOREV}/doc
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGINFODIR}

PRINT_PLIST_AWK+=	{ gsub(/${MACHINE_GNU_PLATFORM}/, "$${MACHINE_GNU_PLATFORM}"); }
CHECK_WRKREF_SKIP+=	lib/octave/${PKGVERSION_NOREV}/liboctinterp*.${SHLIB_TYPE}* \
			lib/octave/${PKGVERSION_NOREV}/liboctinterp.a

SUBST_CLASSES+=			fix-make
SUBST_STAGE.fix-make=		pre-configure
SUBST_MESSAGE.fix-make=		Fixing path to gmake.
SUBST_FILES.fix-make=		scripts/pkg/private/configure_make.m
SUBST_VARS.fix-make=		GMAKE

SUBST_CLASSES+=			qtchooser
SUBST_STAGE.qtchooser=		pre-configure
SUBST_MESSAGE.qtchooser=	Avoiding qtchooser assumption (-qt=x argument)
SUBST_FILES.qtchooser=		configure
SUBST_SED.qtchooser=		-e 's,-qt=\$$qt_version,,'

# Matches reduce-relocations logic in x11/qt5-qtbase
.if ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS" && \
	${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == x86_64
CFLAGS+=	-fPIC
.endif

PREPEND_PATH+=		${QTDIR}/bin

CHECK_WRKREF_SKIP+=	lib/octave/${PKGVERSION_NOREV}/liboctinterp.so*

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
.for f in ${OCTAVE_DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/octave/${PKGVERSION_NOREV}/doc
.endfor
.for f in ${OCTAVE_MAN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
.for f in ${OCTAVE_INFO}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${PKGINFODIR}
.endfor
	${RM} -f ${DESTDIR}/${PREFIX}/lib/charset.alias

.if ${OPSYS} != "Darwin"
# Also can use osmesa for plotting.
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gl2ps/buildlink3.mk"
.include "../../math/arpack-ng/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/qrupdate/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
