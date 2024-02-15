# $NetBSD: Makefile,v 1.8 2024/02/15 19:38:14 markd Exp $

DISTNAME=	pst-math
PKGNAME=	tex-${DISTNAME}-0.67
TEXLIVE_REV=	67535

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-math
COMMENT=	Enhancement of PostScript math operators to use with PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
