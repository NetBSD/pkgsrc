# $NetBSD: Makefile,v 1.9 1999/08/26 23:52:21 jlam Exp $
#

DISTNAME=	R-0.64.2
CATEGORIES=	math
MASTER_SITES=	http://lib.stat.cmu.edu/R/CRAN/src/base/ \
		ftp://ftp.biostat.washington.edu/mirrors/R/CRAN/src/base/ \
		http://cran.stat.wisc.edu/src/base/ \
		http://SunSITE.auc.dk/R/src/base/ \
		http://www.stat.unipg.it/pub/stat/statlib/R/CRAN/src/base/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/ \
		ftp://dola.snu.ac.kr/pub/R/CRAN/src/base/ \
		http://stat.ethz.ch/CRAN/src/base/ \
		http://www.stats.bris.ac.uk/R/src/base/ \
		ftp://ftp.ci.tuwien.ac.at/pub/R/src/base/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://lib.stat.cmu.edu/R/CRAN/

.if !exists(/usr/bin/f77)
DEPENDS+=	f2c-19980913:../../lang/f2c
.endif
DEPENDS+=	readline-4.0:../../devel/readline

USE_X11=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-readline --with-x

.include "../../mk/bsd.prefs.mk"

# R_PAPERSIZE can be: A4, Letter, Legal, Executive
#
.if defined(PAPERSIZE)
R_PAPERSIZE?=	${PAPERSIZE}
.else
R_PAPERSIZE?=	A4
.endif
.if (${R_PAPERSIZE} == "Letterdj")
R_PAPERSIZE=	Letter
.endif

.if (${OPSYS} == "SunOS")
BSD_INSTALL?=	/usr/ucb/install
.else
BSD_INSTALL?=	/usr/bin/install
.endif
INSTALL_OWN_SCRIPT=	${BSD_INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_SCRIPT=		${BSD_INSTALL} ${COPY} -m ${BINMODE}
INSTALL_DATA=		${BSD_INSTALL} ${COPY} -m 644
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lreadline
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			R_PAPERSIZE="${R_PAPERSIZE}"
MAKE_ENV+=		INSTALL_OWN_SCRIPT="${INSTALL_OWN_SCRIPT}"

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/R

.include "../../mk/bsd.pkg.mk"
