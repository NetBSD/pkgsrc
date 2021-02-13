# $NetBSD: Makefile,v 1.10 2021/02/13 10:39:12 markd Exp $

DISTNAME=	eso-pic
PKGNAME=	tex-${DISTNAME}-3.0a
TEXLIVE_REV=	56658

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/eso-pic
COMMENT=	Add picture commands (or backgrounds) to every page
LICENSE=	lppl-1.2

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
