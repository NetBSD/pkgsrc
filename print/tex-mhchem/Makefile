# $NetBSD: Makefile,v 1.13 2024/02/14 19:38:56 markd Exp $

DISTNAME=	mhchem
PKGNAME=	tex-${DISTNAME}-4.10
TEXLIVE_REV=	69639

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mhchem
COMMENT=	Typeset chemical formulae/equations and H and P statements
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-chemgreek-[0-9]*:../../print/tex-chemgreek
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-latex>=2009:../../print/tex-latex
DEPENDS+=	tex-oberdiek>=2009nb2:../../print/tex-oberdiek
DEPENDS+=	tex-pgf>=2.00nb1:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
