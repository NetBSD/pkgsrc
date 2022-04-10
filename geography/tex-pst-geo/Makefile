# $NetBSD: Makefile,v 1.5 2022/04/10 06:21:01 markd Exp $

DISTNAME=	pst-geo
PKGNAME=	tex-${DISTNAME}-2.07
TEXLIVE_REV=	60387

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-geo
COMMENT=	Geographical Projections
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
