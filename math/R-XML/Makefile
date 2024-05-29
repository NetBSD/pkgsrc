# $NetBSD: Makefile,v 1.26 2024/05/29 16:33:26 adam Exp $

R_PKGNAME=	XML
R_PKGVER=	3.99-0.16.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for parsing and generating XML within R
PKGREVISION=	1
LICENSE=	2-clause-bsd

DEPENDS+=	R-bitops-[0-9]*:../../math/R-bitops
DEPENDS+=	R-RCurl-[0-9]*:../../www/R-RCurl

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
