# $NetBSD: Makefile,v 1.12 2000/04/19 15:30:05 jlam Exp $
#

DISTNAME=		R-1.0.1
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
HOMEPAGE=		http://cran.r-project.org/

DEPENDS+=		readline>=4.0:../../devel/readline

USE_FORTRAN=		# defined
USE_X11=		# defined
USE_PERL5=		# defined
USE_GMAKE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-readline --with-x
CONFIGURE_ARGS+=	--without-gnome --without-libmoto
CONFIGURE_ARGS+=	--without-blas --without-blas-risc
CONFIGURE_ARGS+=	--without-dxml
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=		MAKE="${LOCALBASE}/bin/gmake"
CPPFLAGS+=		-I${LOCALBASE}/include		# readline/readline.h

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

.if (${OPSYS} == "SunOS")
BSD_INSTALL?=	/usr/ucb/install
.else
BSD_INSTALL?=	/usr/bin/install
.endif
INSTALL_OWN_SCRIPT=	${BSD_INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_SCRIPT=		${BSD_INSTALL} ${COPY} -m ${BINMODE}
INSTALL_DATA=		${BSD_INSTALL} ${COPY} -m 644

MAKE_ENV+=		INSTALL_OWN_SCRIPT="${INSTALL_OWN_SCRIPT}"

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/R

.include "../../mk/bsd.pkg.mk"
