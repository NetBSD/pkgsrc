# $NetBSD: Makefile,v 1.1 2019/10/13 11:50:49 rillig Exp $

R_PKGNAME=	covr
R_PKGVER=	3.3.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test Coverage for Packages
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-withr>=1.0.2:../../devel/R-withr
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-yaml>=2.2.0:../../textproc/R-yaml
DEPENDS+=	R-httr>=1.4.1:../../www/R-httr
DEPENDS+=	R-rex>=0:../../devel/R-rex

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
