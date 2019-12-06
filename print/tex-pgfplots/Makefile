# $NetBSD: Makefile,v 1.9 2019/12/06 20:23:02 markd Exp $

DISTNAME=	pgfplots
PKGNAME=	tex-${DISTNAME}-1.16
TEXLIVE_REV=	47373

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pgfplots
COMMENT=	LaTeX package to create normal/logarithmic plots
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
