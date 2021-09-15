# $NetBSD: Makefile,v 1.1 2021/09/15 12:33:17 mef Exp $

MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cran.r-project.org/web/packages/gsl/
COMMENT=	R wrapper for the Gnu Scientific Library
LICENSE=	gnu-gpl-v2

R_PKGNAME=	gsl
R_PKGVER=	2.1-6

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0
BUILDLINK_API_DEPENDS.gsl+=	gsl>=1.12

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
