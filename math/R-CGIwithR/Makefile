# $NetBSD: Makefile,v 1.25 2019/03/18 16:17:49 gdt Exp $
#

PKGREVISION=		18
CATEGORIES=		math

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
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		inst/cgi-bin/R.cgi
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'

.include "../../math/R/Makefile.extension"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
