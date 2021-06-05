# $NetBSD: Makefile,v 1.12 2021/06/05 05:31:03 markd Exp $

DISTNAME=	pgfplots
PKGNAME=	tex-${DISTNAME}-1.18.1
TEXLIVE_REV=	59243

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pgfplots
COMMENT=	LaTeX package to create normal/logarithmic plots
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
