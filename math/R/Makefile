# $NetBSD: Makefile,v 1.35 2002/06/16 02:56:50 dmcmahill Exp $

DISTNAME=		R-1.4.1
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=base/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.R-project.org/
COMMENT=		Statistical language for data analysis and graphics

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

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

REPLACE_BUILDLINK=	src/scripts/R.fe etc/Makeconf
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
	) | ${GREP} -v "lib/R/doc/html/packages.html" |			\
	${GREP} -v "lib/R/doc/html/search/index.txt" | 			\
	${SORT} -u >> ${PLIST_SRC}
	${ECHO} "@unexec ${RM} -f %D/lib/R/doc/html/packages.html" >> ${PLIST_SRC}
	${ECHO} "@unexec ${RM} -f %D/lib/R/doc/html/search/index.txt" >> ${PLIST_SRC}
	( cd ${PREFIX};							\
	  for dir in ${INSTALL_DIRS}; do				\
		${FIND} $${dir#${PREFIX}/} -type d -print;		\
	  done;								\
	) | ${SORT} -ur | ${SED} -e "s|^|@dirrm |" >> ${PLIST_SRC}
	${ECHO} "@exec R CMD ${PERL5} %D/lib/R/share/perl/build-help.pl --htmllists 2>/dev/null" >> ${PLIST_SRC}
	${ECHO} "@exec ${CAT} %D/lib/R/library/*/CONTENTS > %D/lib/R/doc/html/search/index.txt 2>/dev/null" >> ${PLIST_SRC}

.include "../../devel/readline/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../math/blas/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
