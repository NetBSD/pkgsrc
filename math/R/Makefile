# $NetBSD: Makefile,v 1.4 1999/02/20 22:48:35 hubertf Exp $
#

DISTNAME=	R-0.63.1
CATEGORIES=	math
MASTER_SITES=	http://lib.stat.cmu.edu/R/CRAN/src/base/ \
		ftp://ftp.biostat.washington.edu/mirrors/R/CRAN/src/base/ \
		http://cran.stat.wisc.edu/src/base/ \
		ftp://ftp.ci.tuwien.ac.at/R/src/base/ \
		http://SunSITE.auc.dk/R/src/base/ \
		http://www.stat.unipg.it/pub/stat/statlib/R/CRAN/src/base/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/ \
		ftp://dola.snu.ac.kr/pub/R/CRAN/src/base/ \
		http://www.stat.math.ethz.ch/R-CRAN/src/base/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lamj@stat.cmu.edu
HOMEPAGE=	http://lib.stat.cmu.edu/R/CRAN/

.if !exists(/usr/bin/f77)
DEPENDS+=	f2c-19980913:../../lang/f2c
.endif
DEPENDS+=	readline-2.2:../../devel/readline

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-readline --with-x

.include "../../mk/bsd.prefs.mk"

# R_PAPERSIZE can be: A4, Letter, Legal, Executive
#
.if defined(PAPERSIZE)
R_PAPERSIZE?=	${PAPERSIZE}
.if (${R_PAPERSIZE} == "Letterdj")
R_PAPERSIZE=	Letter
.endif
.endif

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		R_PAPERSIZE="${R_PAPERSIZE}"

post-install:
	${RMDIR} ${PREFIX}/share/R/library/modreg/data

.include "../../mk/bsd.pkg.mk"
