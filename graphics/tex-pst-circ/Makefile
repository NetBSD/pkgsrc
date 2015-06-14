# $NetBSD: Makefile,v 1.3 2015/06/14 11:26:43 markd Exp $

DISTNAME=	pst-circ
PKGNAME=	tex-${DISTNAME}-2.13
TEXLIVE_REV=	36865

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PSTricks package for drawing electric circuits
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
