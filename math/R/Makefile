# $NetBSD: Makefile,v 1.91 2007/03/28 11:06:29 dmcmahill Exp $

DISTNAME=		R-2.4.1
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=base/R-2/}

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.R-project.org/
COMMENT=		Statistical language for data analysis and graphics

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

PKG_INSTALLATION_TYPES=	overwrite pkgviews

TEST_TARGET=		check
USE_TOOLS+=		gmake gzip:run makeinfo perl:run sed xmkmf
USE_GNU_READLINE=	yes		# uses callback interface
USE_LANGUAGES=		c fortran
USE_LIBTOOL=		yes
TEXINFO_REQD=		4.7

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

# Use BLAS (math/blas)
#
CONFIGURE_ARGS+=	--without-atlas
CONFIGURE_ARGS+=	--with-blas
CONFIGURE_ARGS+=	--without-blas_risc
CONFIGURE_ARGS+=	--without-dxml
CONFIGURE_ARGS+=	--without-libmoto

# Work around missing MAIN__() definition used in -lF77 by AC_CHECK_LIB.
CONFIGURE_ENV+=		ac_cv_lib_blas_dgemm=yes
CONFIGURE_ENV+=		ac_cv_lib_blas_dgemm_=yes

CONFIGURE_ENV+=		GETWD=${TOOLS_PWD_CMD:Q}
CONFIGURE_ENV+=		lt_cv_path_LD=${LD:Q}
CONFIGURE_ENV+=		lt_cv_path_SED=${TOOLS_SED:Q}
CONFIGURE_ENV+=		ac_cv_path_R_GZIPCMD=${TOOLS_GZIP_CMD:Q}

# Package assumes it can append to files (specifically DESCRIPTION) that have
# been installed SHAREMODE
SHAREMODE=		644

.include "../../mk/bsd.prefs.mk"

# R_PAPERSIZE can be: A4, Letter, Legal, Executive
#
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
#
INSTALL_DATA=		${INSTALL} ${COPY} -m ${SHAREMODE}
INSTALL_SCRIPT=		${INSTALL} ${COPY} -m ${BINMODE}

BUILDLINK_API_DEPENDS.zlib+= zlib>=1.2.1

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M1.[0-6]*)
CONFIGURE_ARGS+=	--enable-mbcs=no
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

INSTALL_TEMPLATES+=	../../math/R/files/pkg-index.tmpl
DEINSTALL_TEMPLATES+=	../../math/R/files/pkg-index.tmpl
PRINT_PLIST_AWK+=	/^lib\/R\/doc\/html\/packages.html$$/ { next; }
PRINT_PLIST_AWK+=	/^lib\/R\/doc\/html\/search\/index.txt$$/ { next; }

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/R

.include "../../mk/bsd.pkg.mk"
