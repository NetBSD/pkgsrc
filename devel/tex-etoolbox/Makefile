# $NetBSD: Makefile,v 1.6 2018/05/06 02:40:13 markd Exp $

DISTNAME=	etoolbox
PKGNAME=	tex-${DISTNAME}-2.5e
TEXLIVE_REV=	46602

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etoolbox
COMMENT=	e-TeX tools for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
