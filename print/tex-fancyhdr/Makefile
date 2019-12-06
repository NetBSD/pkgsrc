# $NetBSD: Makefile,v 1.10 2019/12/06 20:21:22 markd Exp $

DISTNAME=	fancyhdr
PKGNAME=	tex-${DISTNAME}-3.10
TEXLIVE_REV=	49886

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fancyhdr
COMMENT=	Extensive control of page headers and footers in LaTeX2e
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
