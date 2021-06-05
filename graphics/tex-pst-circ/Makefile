# $NetBSD: Makefile,v 1.10 2021/06/05 05:48:04 markd Exp $

DISTNAME=	pst-circ
PKGNAME=	tex-${DISTNAME}-2.18
TEXLIVE_REV=	59017

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-circ
COMMENT=	PSTricks package for drawing electric circuits
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
