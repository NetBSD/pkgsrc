# $NetBSD: Makefile,v 1.1.1.1 2011/03/18 21:37:10 minskim Exp $

DISTNAME=	pst-circ
PKGNAME=	tex-${DISTNAME}-2.01
TEXLIVE_REV=	21599

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PSTricks package for drawing electric circuits

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
