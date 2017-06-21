# $NetBSD: Makefile,v 1.3 2017/06/21 11:45:59 markd Exp $

DISTNAME=	pst-tree
PKGNAME=	tex-${DISTNAME}-1.13
TEXLIVE_REV=	43272

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-tree
COMMENT=	Trees, using pstricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
