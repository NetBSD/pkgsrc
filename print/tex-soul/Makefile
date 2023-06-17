# $NetBSD: Makefile,v 1.7 2023/06/17 10:43:51 markd Exp $

DISTNAME=	soul
PKGNAME=	tex-${DISTNAME}-3.1
TEXLIVE_REV=	67365

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/soul
COMMENT=	Hyphenation for letterspacing, underlining, and more
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
