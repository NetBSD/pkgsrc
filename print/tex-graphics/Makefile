# $NetBSD: Makefile,v 1.17 2020/01/18 23:34:14 rillig Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.2c.47350
TEXLIVE_REV=	47350

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-graphics
COMMENT=	Standard LaTeX graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
