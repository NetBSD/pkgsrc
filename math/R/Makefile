# $NetBSD: Makefile,v 1.29 2001/12/11 22:35:07 jlam Exp $

DISTNAME=		R-1.3.0
CATEGORIES=		math
MASTER_SITES=		http://lib.stat.cmu.edu/R/CRAN/src/base/ \
			http://cran.r-project.org/src/base/ \
			ftp://cran.r-project.org/pub/R/src/base/ \
			http://cran.stat.wisc.edu/src/base/ \
			http://SunSITE.auc.dk/R/src/base/ \
			ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/ \
			ftp://dola.snu.ac.kr/pub/R/CRAN/src/base/ \
			http://stat.ethz.ch/CRAN/src/base/ \
			http://www.stats.bris.ac.uk/R/src/base/ \
			http://cran.at.r-project.org/src/base/ \
			ftp://cran.at.r-project.org/pub/R/src/base/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.R-project.org/
COMMENT=		Statistical language for data analysis and graphics

USE_BUILDLINK_ONLY=	# defined
USE_X11=		# defined
USE_PERL5=		# defined
USE_GMAKE=		# defined
USE_GNU_READLINE=	# uses callback interface

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-tcltk
CONFIGURE_ARGS+=	--with-tcl-config=${BUILDLINK_DIR}/lib/tclConfig.sh
CONFIGURE_ARGS+=	--with-tk-config=${BUILDLINK_DIR}/lib/tkConfig.sh
CONFIGURE_ARGS+=	--without-gnome		# not yet stable
CONFIGURE_ENV+=		XMKMF="${XMKMF}"

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

# Pass the Fortran compiler to the configure script in case it's overridden
# by the package builder.
#
USE_FORTRAN=		# defined
CONFIGURE_ENV+=		FC="${FC}"

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
CONFIGURE_ENV+=		R_PAPERSIZE="${R_PAPERSIZE}"

# These macros are used during the build, so strip off the -o,-g flags.
#
INSTALL_DATA=		${INSTALL} ${COPY} -m ${SHAREMODE}
INSTALL_SCRIPT=		${INSTALL} ${COPY} -m ${BINMODE}

PLIST_SRC=		${WRKDIR}/.PLIST_SRC
R_LIBDIR=		${PREFIX}/lib/R
INSTALL_DIRS=		${R_LIBDIR}

REPLACE_BUILDLINK=	src/scripts/R.fe
REPLACE_BUILDLINK_SED=	-e "s|${BUILDLINK_DIR}/|${LOCALBASE}/|g"

# Generate the PLIST dynamically as it changes in each version only in a
# specific subtree.  This will make maintaining this package a little easier
# when updating.
#
post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${R_LIBDIR}
	${RM} -f ${PLIST_SRC}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	( cd ${PREFIX};							\
	  for dir in ${INSTALL_DIRS}; do				\
		${FIND} $${dir#${PREFIX}/} \( -type f -or -type l \) -print; \
	  done;								\
	) | ${SORT} -u >> ${PLIST_SRC}
	( cd ${PREFIX};							\
	  for dir in ${INSTALL_DIRS}; do				\
		${FIND} $${dir#${PREFIX}/} -type d -print;		\
	  done;								\
	) | ${SORT} -ur | ${SED} -e "s|^|@dirrm |" >> ${PLIST_SRC}

.include "../../devel/readline/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../math/blas/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
