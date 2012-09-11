# $NetBSD: Makefile,v 1.129 2012/09/11 23:04:15 asau Exp $

DISTNAME=		R-2.14.2
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=base/R-2/}

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.R-project.org/
COMMENT=		Statistical language for data analysis and graphics
LICENSE=		gnu-gpl-v2

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

PKG_INSTALLATION_TYPES=	overwrite pkgviews

TEST_TARGET=		check
USE_TOOLS+=		gmake gzip:run makeinfo perl:run sed unzip:run xmkmf
USE_TOOLS+=		pkg-config
USE_GNU_READLINE=	yes		# uses callback interface
USE_GNU_ICONV=		yes		# latin1 support, iconvlist
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
TEXINFO_REQD=		4.7

PTHREAD_AUTO_VARS=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-R-shlib
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-tcltk
CONFIGURE_ARGS+=	--with-tcl-config=${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
CONFIGURE_ARGS+=	--with-tk-config=${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh
CONFIGURE_ARGS+=	--without-gnome		# not yet stable
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-system-bzlib
CONFIGURE_ARGS+=	--with-system-pcre
CONFIGURE_ARGS+=	--with-system-xz

# Disable Mac OS specific support used by R.app
CONFIGURE_ARGS+=	--disable-R-framework
CONFIGURE_ARGS+=	--without-aqua

# Use BLAS (math/blas)
CONFIGURE_ARGS+=	--without-atlas
CONFIGURE_ARGS+=	--disable-BLAS-shlib
CONFIGURE_ARGS+=	--with-blas
CONFIGURE_ARGS+=	--without-blas_risc
CONFIGURE_ARGS+=	--without-dxml
CONFIGURE_ARGS+=	--without-libmoto

# Work around missing MAIN__() definition used in -lF77 by AC_CHECK_LIB.
# and other failures due to not linking to support libs during testing
CONFIGURE_ENV+=		ac_cv_lib_blas_dgemm=yes
CONFIGURE_ENV+=		ac_cv_lib_blas_dgemm_=yes
CONFIGURE_ENV+=		r_cv_complete_blas=yes

# Broken test for bzlib >= 1.0.5 in R 2.7.0
CONFIGURE_ENV+=		r_cv_have_bzlib=yes

CONFIGURE_ENV+=		GETWD=${TOOLS_PWD_CMD}
CONFIGURE_ENV+=		lt_cv_path_LD=${LD:Q}
CONFIGURE_ENV+=		lt_cv_path_SED=${TOOLS_SED}
CONFIGURE_ENV+=		ac_cv_path_R_GZIPCMD=${TOOLS_GZIP_CMD}
CONFIGURE_ENV+=		ac_cv_path_R_UNZIPCMD=${TOOLS_PATH.unzip}
CONFIGURE_ENV+=		r_cv_prog_f77_flag_mieee=no

# We don't want "lib64"
CONFIGURE_ENV+=		LIBnn=lib

# Package assumes it can append to files (specifically DESCRIPTION) that have
# been installed SHAREMODE
SHAREMODE=		644

.include "../../mk/bsd.prefs.mk"

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

# to build NEWS.pdf
BUILD_DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=		tex-metafont-[0-9]*:../../fonts/tex-metafont
BUILD_DEPENDS+=		tex-ae-[0-9]*:../../fonts/tex-ae
BUILD_DEPENDS+=		tex-ec-[0-9]*:../../fonts/tex-ec
BUILD_DEPENDS+=		tex-tools-[0-9]*:../../print/tex-tools
BUILD_DEPENDS+=		tex-url-[0-9]*:../../print/tex-url
BUILD_DEPENDS+=		tex-oberdiek-[0-9]*:../../print/tex-oberdiek
BUILD_DEPENDS+=		tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
BUILD_DEPENDS+=		tex-cm-[0-9]*:../../fonts/tex-cm
BUILD_DEPENDS+=		tex-cm-super-[0-9]*:../../fonts/tex-cm-super
BUILD_DEPENDS+=		tex-fontname-[0-9]*:../../fonts/tex-fontname
BUILD_DEPENDS+=		tex-graphics-[0-9]*:../../print/tex-graphics
BUILD_DEPENDS+=		tex-hyperref-[0-9]*:../../print/tex-hyperref
BUILD_DEPENDS+=		tex-ifluatex-[0-9]*:../../print/tex-ifluatex
BUILD_DEPENDS+=		tex-ifxetex-[0-9]*:../../print/tex-ifxetex
BUILD_DEPENDS+=		tex-latex-[0-9]*:../../print/tex-latex
BUILD_DEPENDS+=		tex-latexconfig-[0-9]*:../../print/tex-latexconfig
BUILD_DEPENDS+=		tex-mptopdf-[0-9]*:../../graphics/tex-mptopdf
BUILD_DEPENDS+=		tex-pdftex-def-[0-9]*:../../print/tex-pdftex


BUILDLINK_API_DEPENDS.zlib+= zlib>=1.2.3
BUILDLINK_API_DEPENDS.bzip2+= bzip2>=1.0.5

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M1.[0-6]*)
CONFIGURE_ARGS+=	--enable-mbcs=no
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

INSTALL_TEMPLATES+=	../../math/R/files/pkg-index.tmpl
DEINSTALL_TEMPLATES+=	../../math/R/files/pkg-index.tmpl
PRINT_PLIST_AWK+=	/^lib\/R\/doc\/html\/packages.html$$/ { next; }

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
