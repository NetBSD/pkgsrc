# $NetBSD: Makefile,v 1.4 2019/12/06 20:04:34 markd Exp $

DISTNAME=	pst-poly
PKGNAME=	tex-${DISTNAME}-1.63
TEXLIVE_REV=	35062

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Polygons with PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
