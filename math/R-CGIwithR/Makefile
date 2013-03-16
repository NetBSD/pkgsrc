# $NetBSD: Makefile,v 1.10 2013/03/16 22:54:29 dholland Exp $
#

PKGREVISION=		6
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		${R_HOMEPAGE_BASE}/CGIwithR/
COMMENT=		Facilities for the use of R to write CGI scripts

R_PKGNAME=		CGIwithR
R_PKGVER=		0.73-0

REPLACE_INTERPRETER+=	r
REPLACE.r.old=		.*R
REPLACE.r.new=		${PREFIX}/bin/R
REPLACE_FILES.r=	inst/examples/dangerous.R inst/examples/trivial.R

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		inst/cgi-bin/R.cgi
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'

.include "../../math/R/Makefile.extension"
.include "../../print/ghostscript/ghostscript.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
