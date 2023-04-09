# $NetBSD: Makefile,v 1.6 2023/04/09 06:22:20 markd Exp $

DISTNAME=	soul
PKGNAME=	tex-${DISTNAME}-3.0
TEXLIVE_REV=	65908

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/soul
COMMENT=	Hyphenation for letterspacing, underlining, and more
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
