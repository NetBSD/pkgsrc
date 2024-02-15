# $NetBSD: Makefile,v 1.14 2024/02/15 19:33:25 markd Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-13.3
TEXLIVE_REV=	69470

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/preview
COMMENT=	Extract bits of a LaTeX source for output
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
