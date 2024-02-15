# $NetBSD: Makefile,v 1.4 2024/02/15 19:40:37 markd Exp $

DISTNAME=	pst-osci
PKGNAME=	tex-${DISTNAME}-2.82b
TEXLIVE_REV=	68781

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-osci
COMMENT=	Oscgons with PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
