# $NetBSD: Makefile,v 1.12 2022/04/14 03:22:39 markd Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-13.1
TEXLIVE_REV=	62130

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/preview
COMMENT=	Extract bits of a LaTeX source for output
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
