# $NetBSD: Makefile,v 1.1.1.1 2011/03/18 21:49:31 minskim Exp $

DISTNAME=	pst-uml
PKGNAME=	tex-${DISTNAME}-0.83
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	UML diagrams with PSTricks

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pst-tree-[0-9]*:../../graphics/tex-pst-tree
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
