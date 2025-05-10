# $NetBSD: Makefile,v 1.6 2025/05/10 22:56:11 markd Exp $

DISTNAME=	pst-geo
PKGNAME=	tex-${DISTNAME}-0.09
TEXLIVE_REV=	74247

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-geo
COMMENT=	Geographical Projections
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
