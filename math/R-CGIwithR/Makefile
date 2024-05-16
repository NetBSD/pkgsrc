# $NetBSD: Makefile,v 1.46 2024/05/16 06:15:08 wiz Exp $

R_PKGNAME=	CGIwithR
R_PKGVER=	0.73-0
PKGREVISION=	37
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Facilities for the use of R to write CGI scripts

USE_LANGUAGES=	# none

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
