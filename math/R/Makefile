# $NetBSD: Makefile,v 1.22 2001/05/22 09:32:24 wiz Exp $
#

DISTNAME=		R-1.1.1
CATEGORIES=		math
MASTER_SITES=		http://cran.r-project.org/src/base/ \
			ftp://cran.r-project.org/pub/R/src/base/ \
			http://lib.stat.cmu.edu/R/CRAN/src/base/ \
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

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
DEPENDS+=		readline>=4.0:../../devel/readline
DEPENDS+=		jpeg-*:../../graphics/jpeg
DEPENDS+=		png>=1.0.11:../../graphics/png

# Requires IEEE math
NOT_FOR_PLATFORM=	*-*-alpha

USE_FORTRAN=		# defined
USE_X11=		# defined
USE_PERL5=		# defined
USE_GMAKE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--without-gnome			# not yet stable
CONFIGURE_ARGS+=	--without-tcltk			# not yet stable
CONFIGURE_ARGS+=	--without-atlas
CONFIGURE_ARGS+=	--without-blas
CONFIGURE_ARGS+=	--without-blas_risc
CONFIGURE_ARGS+=	--without-dxml
CONFIGURE_ARGS+=	--without-libmoto

CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=		LIBS="${LIBS}"
CONFIGURE_ENV+=		MAKE="${MAKE_PROGRAM}"

CPPFLAGS+=		-I${LOCALBASE}/include		# readline/readline.h
LIBS+=			-ltermcap			# -lreadline -ltermcap

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

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

# Generate the PLIST dynamically as it changes in each version only in a
# specific subtree.  This will make maintaining this package a little easier
# when updating.
#
post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${R_LIBDIR}
	${RM} -f ${PLIST_SRC}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	( cd ${PREFIX}; \
	  for dir in ${INSTALL_DIRS}; do \
		${FIND} $${dir#${PREFIX}/} \( -type f -or -type l \) -print; \
	  done; \
	) | sort -u >> ${PLIST_SRC}
	( cd ${PREFIX}; \
	  for dir in ${INSTALL_DIRS}; do \
		${FIND} $${dir#${PREFIX}/} -type d -print; \
	  done; \
	) | sort -ur | ${SED} -e "s,^,@dirrm ," >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
