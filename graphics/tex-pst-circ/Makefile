# $NetBSD: Makefile,v 1.9 2021/02/15 11:00:37 markd Exp $

DISTNAME=	pst-circ
PKGNAME=	tex-${DISTNAME}-2.17
TEXLIVE_REV=	55289

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
