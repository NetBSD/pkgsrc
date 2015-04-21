# $NetBSD: Makefile,v 1.2 2015/04/21 23:51:58 markd Exp $

DISTNAME=	pst-circ
PKGNAME=	tex-${DISTNAME}-2.12a
TEXLIVE_REV=	35347

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PSTricks package for drawing electric circuits

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
