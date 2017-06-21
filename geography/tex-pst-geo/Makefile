# $NetBSD: Makefile,v 1.2 2017/06/21 11:45:58 markd Exp $

DISTNAME=	pst-geo
PKGNAME=	tex-${DISTNAME}-2.06
TEXLIVE_REV=	44131

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-geo
COMMENT=	Geographical Projections
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
