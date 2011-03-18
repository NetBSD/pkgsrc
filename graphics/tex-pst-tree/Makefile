# $NetBSD: Makefile,v 1.1.1.1 2011/03/18 21:43:51 minskim Exp $

DISTNAME=	pst-tree
PKGNAME=	tex-${DISTNAME}-1.12
TEXLIVE_REV=	21589

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Trees, using pstricks

DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
