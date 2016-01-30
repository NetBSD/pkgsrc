# $NetBSD: Makefile,v 1.2 2016/01/30 04:05:54 markd Exp $

DISTNAME=	pst-tree
PKGNAME=	tex-${DISTNAME}-1.12
TEXLIVE_REV=	21589

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Trees, using pstricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
