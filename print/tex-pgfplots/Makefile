# $NetBSD: Makefile,v 1.7 2016/06/16 04:06:14 markd Exp $

DISTNAME=	pgfplots
PKGNAME=	tex-${DISTNAME}-1.13
TEXLIVE_REV=	40966

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pgfplots
COMMENT=	LaTeX package to create normal/logarithmic plots
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
