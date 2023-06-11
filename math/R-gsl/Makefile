# $NetBSD: Makefile,v 1.3 2023/06/11 06:50:07 mef Exp $

MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cran.r-project.org/web/packages/gsl/
COMMENT=	R wrapper for the Gnu Scientific Library
LICENSE=	gnu-gpl-v2

R_PKGNAME=	gsl
R_PKGVER=	2.1-8

TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-ae-[0-9]*:../../fonts/tex-ae
TEST_DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg


USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0
BUILDLINK_API_DEPENDS.gsl+=	gsl>=1.12

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
