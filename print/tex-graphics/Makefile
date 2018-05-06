# $NetBSD: Makefile,v 1.15 2018/05/06 04:15:45 markd Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.2c.47350
TEXLIVE_REV=	47350

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-graphics
COMMENT=	Standard LaTeX graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
