# $NetBSD: Makefile,v 1.11 2020/01/18 23:34:07 rillig Exp $

DISTNAME=	fancyhdr
PKGNAME=	tex-${DISTNAME}-3.10
TEXLIVE_REV=	49886

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fancyhdr
COMMENT=	Extensive control of page headers and footers in LaTeX2e
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
