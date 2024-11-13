# $NetBSD: Makefile,v 1.11 2024/11/13 01:33:19 markd Exp $

DISTNAME=	cyrillic
PKGNAME=	tex-${DISTNAME}-20240603
TEXLIVE_REV=	71408

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-cyrillic
COMMENT=	Support for Cyrillic fonts in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-cyrillic-bin-[0-9]*:../../print/tex-cyrillic-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
