# $NetBSD: Makefile,v 1.8 2019/12/06 19:18:33 markd Exp $

DISTNAME=	etoolbox
PKGNAME=	tex-${DISTNAME}-2.5f
TEXLIVE_REV=	48436

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etoolbox
COMMENT=	e-TeX tools for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
