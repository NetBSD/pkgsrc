# $NetBSD: Makefile,v 1.11 2021/02/20 10:40:36 markd Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-12.3
TEXLIVE_REV=	56708

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/preview
COMMENT=	Extract bits of a LaTeX source for output
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
