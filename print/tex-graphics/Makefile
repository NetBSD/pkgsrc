# $NetBSD: Makefile,v 1.14 2017/09/06 16:49:35 wiz Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.2c
TEXLIVE_REV=	44703

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-graphics
COMMENT=	Standard LaTeX graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
