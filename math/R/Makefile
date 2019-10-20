# $NetBSD: Makefile,v 1.205 2019/10/20 03:29:10 markd Exp $

DISTNAME=	R-3.6.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=base/R-3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.R-project.org/
COMMENT=	Statistical language for data analysis and graphics
LICENSE=	gnu-gpl-v2

USE_GCC_RUNTIME=	yes

BUILD_TARGET=		all info
INSTALL_TARGET=		install install-info
TEST_TARGET=		check
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoreconf automake gmake gzip:run
USE_TOOLS+=		makeinfo perl:run pkg-config sed unzip:run
TEXINFO_REQD=		5.1
INFO_FILES=		yes

PTHREAD_AUTO_VARS=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-R-shlib
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-lapack
CONFIGURE_ARGS+=	--with-tcltk
CONFIGURE_ARGS+=	--with-tcl-config=${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
CONFIGURE_ARGS+=	--with-tk-config=${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
CONFIGURE_ARGS+=	--enable-long-double=no
.endif

.if ${OPSYS} != "Linux"
USE_GNU_ICONV=		yes		# latin1 support, iconvlist
.endif

PLIST_VARS+=		x11

# Disable Mac OS specific support used by R.app
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-R-framework
CONFIGURE_ARGS+=	--with-aqua
CONFIGURE_ARGS+=	--without-x
.else
USE_TOOLS+=		xmkmf
CONFIGURE_ARGS+=	--with-x
PLIST.x11=		yes
.endif

# Use BLAS
.if exists(/System/Library/Frameworks/Accelerate.framework)
CONFIGURE_ARGS+=	--with-blas="-framework Accelerate"
.else
CONFIGURE_ARGS+=	--disable-BLAS-shlib
CONFIGURE_ARGS+=	--with-blas
.endif

# Work around missing MAIN__() definition used in -lF77 by AC_CHECK_LIB.
# and other failures due to not linking to support libs during testing
CONFIGURE_ENV+=		ac_cv_lib_blas_dgemm=yes
CONFIGURE_ENV+=		ac_cv_lib_blas_dgemm_=yes
CONFIGURE_ENV+=		r_cv_complete_blas=yes

# Broken test for bzlib >= 1.0.5 in R 2.7.0
CONFIGURE_ENV+=		r_cv_have_bzlib=yes
# Override zlib 1.2.5 requirement
CONFIGURE_ENV+=		r_cv_header_zlib_h=yes

CONFIGURE_ENV+=		GETWD=${TOOLS_PWD_CMD}
CONFIGURE_ENV+=		lt_cv_path_LD=${LD:Q}
CONFIGURE_ENV+=		lt_cv_path_SED=${TOOLS_SED}
CONFIGURE_ENV+=		ac_cv_path_R_GZIPCMD=${TOOLS_GZIP_CMD}
CONFIGURE_ENV+=		ac_cv_path_R_UNZIPCMD=${TOOLS_PATH.unzip}
CONFIGURE_ENV+=		r_cv_prog_f77_flag_mieee=no
CONFIGURE_ENV+=		ac_cv_path_PDFLATEX=""

# We don't want "lib64"
CONFIGURE_ENV+=		LIBnn=lib

# Package assumes it can append to files (specifically DESCRIPTION) that have
# been installed SHAREMODE
SHAREMODE=		644

CONFIGURE_ARGS.Darwin+=	--disable-openmp

# R_PAPERSIZE can be: A4, Letter, Legal, Executive
.if defined(PAPERSIZE)
R_PAPERSIZE?=		${PAPERSIZE}
.else
R_PAPERSIZE?=		A4
.endif
.if (${R_PAPERSIZE} == "Letterdj")
R_PAPERSIZE=		Letter
.endif
CONFIGURE_ENV+=		R_PAPERSIZE=${R_PAPERSIZE:Q}

# These macros are used during the build, so strip off the -o,-g flags.
INSTALL_DATA=		${INSTALL} ${COPY} -m ${SHAREMODE}
INSTALL_SCRIPT=		${INSTALL} ${COPY} -m ${BINMODE}

## to build NEWS.pdf
#BUILD_DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
#BUILD_DEPENDS+=		tex-metafont-[0-9]*:../../fonts/tex-metafont
#BUILD_DEPENDS+=		tex-ae-[0-9]*:../../fonts/tex-ae
#BUILD_DEPENDS+=		tex-ec-[0-9]*:../../fonts/tex-ec
#BUILD_DEPENDS+=		tex-tools-[0-9]*:../../print/tex-tools
#BUILD_DEPENDS+=		tex-url-[0-9]*:../../print/tex-url
#BUILD_DEPENDS+=		tex-oberdiek-[0-9]*:../../print/tex-oberdiek
#BUILD_DEPENDS+=		tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
#BUILD_DEPENDS+=		tex-cm-[0-9]*:../../fonts/tex-cm
#BUILD_DEPENDS+=		tex-cm-super-[0-9]*:../../fonts/tex-cm-super
#BUILD_DEPENDS+=		tex-fontname-[0-9]*:../../fonts/tex-fontname
#BUILD_DEPENDS+=		tex-graphics-[0-9]*:../../print/tex-graphics
#BUILD_DEPENDS+=		tex-hyperref-[0-9]*:../../print/tex-hyperref
#BUILD_DEPENDS+=		tex-ifluatex-[0-9]*:../../print/tex-ifluatex
#BUILD_DEPENDS+=		tex-ifxetex-[0-9]*:../../print/tex-ifxetex
#BUILD_DEPENDS+=		tex-latex-[0-9]*:../../print/tex-latex
#BUILD_DEPENDS+=		tex-latexconfig-[0-9]*:../../print/tex-latexconfig
#BUILD_DEPENDS+=		tex-mptopdf-[0-9]*:../../graphics/tex-mptopdf
#BUILD_DEPENDS+=		tex-pdftex-def-[0-9]*:../../print/tex-pdftex

SUBST_CLASSES+=		fixwrap
SUBST_STAGE.fixwrap=	post-build
SUBST_FILES.fixwrap=	libtool
SUBST_SED.fixwrap=	-e "s,${WRAPPER_BINDIR}/libtool,${PKG_LIBTOOL},g"

BUILDLINK_API_DEPENDS.bzip2+=	bzip2>=1.0.5

# failed to convert strong functions and variables: Invalid type identifier
CTF_FILES_SKIP+=	lib/R/library/mgcv/libs/mgcv.so

# Exposes PKG_CONFIG_LIBDIR buildlink paths in a comment.
CHECK_WRKREF_SKIP+=	lib/R/etc/Makeconf

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fvi

# Fix library names.  Relies on build system using -headerpad_max_install_names.
.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	${FIND} ${DESTDIR}${PREFIX} -name "*.so" | while read lib; do	\
		libname=`basename $${lib}`;				\
		libdir=`dirname $${lib} | sed -e 's,${DESTDIR},,'`;	\
		install_name_tool -id $${libdir}/$${libname} $${lib};	\
	done
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
# uses callback interface
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.if !exists(/System/Library/Frameworks/Accelerate.framework)
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.endif
.include "../../www/curl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.if ${OPSYS} != "Darwin"
.include "../../x11/libXt/buildlink3.mk"
.endif

INSTALL_TEMPLATES+=	../../math/R/files/pkg-index.tmpl
DEINSTALL_TEMPLATES+=	../../math/R/files/pkg-index.tmpl
PRINT_PLIST_AWK+=	/^lib\/R\/doc\/html\/packages.html$$/ { next; }

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
