# $NetBSD: Makefile,v 1.64 2005/05/02 16:57:19 drochner Exp $

DISTNAME=		R-2.1.0
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
USE_X11=		# defined
USE_PERL5=		# defined
USE_GNU_TOOLS+=		make
USE_GNU_READLINE=	# uses callback interface
USE_MAKEINFO=		# defined
TEXINFO_REQD=		4.5

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-R-shlib
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-tcltk
CONFIGURE_ARGS+=	--with-tcl-config=${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
CONFIGURE_ARGS+=	--with-tk-config=${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh
CONFIGURE_ARGS+=	--without-gnome		# not yet stable
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-bzlib
CONFIGURE_ARGS+=	--with-pcre
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
USE_LANGUAGES=		c fortran

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
CONFIGURE_ENV+=		R_PAPERSIZE="${R_PAPERSIZE}"

# These macros are used during the build, so strip off the -o,-g flags.
#
INSTALL_DATA=		${INSTALL} ${COPY} -m ${SHAREMODE}
INSTALL_SCRIPT=		${INSTALL} ${COPY} -m ${BINMODE}

PLIST_SRC=		${WRKDIR}/.PLIST_SRC
R_LIBDIR=		${PREFIX}/lib/R
R_INSTALL_DIRS=		${R_LIBDIR}

# R does ugly things in the configure to get the default list of
# arguments for linking Fortran and exposes the buildlink directory
# in various files and scripts that will later be installed, so clean
# up after configure is complete.
#
SUBST_CLASSES+=		fix-R
SUBST_STAGE.fix-R=	post-configure
SUBST_MESSAGE.fix-R=	${SUBST_MESSAGE.unwrap}
SUBST_FILES.fix-R=	etc/Makeconf src/scripts/R.sh src/scripts/f77
SUBST_SED.fix-R=	${SUBST_SED.unwrap}				\
			-e "s|${BUILDLINK_DIR}/|${LOCALBASE}/|g"	\
			-e "s|${BUILDLINK_X11_DIR}/|${X11BASE}/|g"

BUILDLINK_DEPENDS.zlib+= zlib>=1.2.1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

# Generate the PLIST dynamically as it changes in each version only in a
# specific subtree.  This will make maintaining this package a little easier
# when updating.
#
post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${R_LIBDIR}
	${RM} -f ${PLIST_SRC}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	( cd ${PREFIX};							\
	  for dir in ${R_INSTALL_DIRS}; do				\
		${FIND} $${dir#${PREFIX}/} \( -type f -o -type l \) -print; \
	  done;								\
	) | ${GREP} -v "lib/R/doc/html/packages.html" |			\
	${GREP} -v "lib/R/doc/html/search/index.txt" | 			\
	${SORT} -u >> ${PLIST_SRC}
	${ECHO} "@unexec ${RM} -f %D/lib/R/doc/html/packages.html" >> ${PLIST_SRC}
	${ECHO} "@unexec ${RM} -f %D/lib/R/doc/html/search/index.txt" >> ${PLIST_SRC}
	( cd ${PREFIX};							\
	  for dir in ${R_INSTALL_DIRS}; do				\
		${FIND} $${dir#${PREFIX}/} -type d -print;		\
	  done;								\
	) | ${SORT} -ur | ${SED} -e "s|^|@dirrm |" >> ${PLIST_SRC}
	${ECHO} "@exec R CMD ${PERL5} %D/lib/R/share/perl/build-help.pl --htmllists 2>/dev/null" >> ${PLIST_SRC}
	${ECHO} "@exec ${CAT} %D/lib/R/library/*/CONTENTS > %D/lib/R/doc/html/search/index.txt 2>/dev/null" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
