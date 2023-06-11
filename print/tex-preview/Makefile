# $NetBSD: Makefile,v 1.13 2023/06/11 07:35:24 markd Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-13.2
TEXLIVE_REV=	66924

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/preview
COMMENT=	Extract bits of a LaTeX source for output
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
