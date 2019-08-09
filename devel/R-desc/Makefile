# $NetBSD: Makefile,v 1.1 2019/08/09 19:01:08 brook Exp $

R_PKGNAME=	desc
R_PKGVER=	1.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manipulate DESCRIPTION files
LICENSE=	mit

DEPENDS+=	R-assertthat>=0.2.1:../../devel/R-assertthat
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-rprojroot>=1.3.2:../../devel/R-rprojroot

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
