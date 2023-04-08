# $NetBSD: Makefile,v 1.11 2023/04/08 10:08:53 markd Exp $

DISTNAME=	eso-pic
PKGNAME=	tex-${DISTNAME}-3.0b
TEXLIVE_REV=	66655

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/eso-pic
COMMENT=	Add picture commands (or backgrounds) to every page
LICENSE=	lppl-1.2

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
