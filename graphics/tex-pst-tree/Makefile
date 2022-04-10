# $NetBSD: Makefile,v 1.6 2022/04/10 12:25:59 markd Exp $

DISTNAME=	pst-tree
PKGNAME=	tex-${DISTNAME}-1.14
TEXLIVE_REV=	60421

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-tree
COMMENT=	Trees, using PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
