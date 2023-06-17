# $NetBSD: Makefile,v 1.3 2023/06/17 10:56:34 markd Exp $

DISTNAME=	latex-lab
PKGNAME=	tex-${DISTNAME}-2023
TEXLIVE_REV=	67314

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-lab
COMMENT=	LaTeX laboratory
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-bigfoot-[0-9]*:../../print/tex-bigfoot
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-pdfmanagement-testphase-[0-9]*:../../print/tex-pdfmanagement-testphase
DEPENDS+=	tex-tagpdf-[0-9]*:../../print/tex-tagpdf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
