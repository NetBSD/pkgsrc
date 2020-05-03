# $NetBSD: Makefile,v 1.10 2020/05/03 11:57:35 markd Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-12.2
TEXLIVE_REV=	52590

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/preview
COMMENT=	Extract bits of a LaTeX source for output
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
