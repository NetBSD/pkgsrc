# $NetBSD: Makefile,v 1.4 2019/12/06 20:04:36 markd Exp $

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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
