# $NetBSD: Makefile,v 1.6 2020/01/18 23:33:45 rillig Exp $

DISTNAME=	changebar
PKGNAME=	tex-${DISTNAME}-3.6c
TEXLIVE_REV=	46919

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/changebar
COMMENT=	Generate changebars in LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
