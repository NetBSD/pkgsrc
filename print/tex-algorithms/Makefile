# $NetBSD: Makefile,v 1.7 2019/12/06 20:18:47 markd Exp $

DISTNAME=	algorithms
PKGNAME=	tex-${DISTNAME}-0.1
TEXLIVE_REV=	38085

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Suite of tools for typesetting algorithms in pseudo-code
LICENSE=	gnu-lgpl-v2

DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
