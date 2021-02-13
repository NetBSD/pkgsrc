# $NetBSD: Makefile,v 1.9 2021/02/13 11:19:04 markd Exp $

DISTNAME=	ms
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	57473

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ms
COMMENT=	Various LaTeX packages by Martin Schroder
LICENSE=	lppl-1.3c

DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
