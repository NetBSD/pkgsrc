# $NetBSD: Makefile,v 1.4 2024/02/04 09:55:58 markd Exp $

DISTNAME=	latex-lab
PKGNAME=	tex-${DISTNAME}-2023.68720
TEXLIVE_REV=	68720

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
