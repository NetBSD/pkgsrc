# $NetBSD: Makefile,v 1.8 2019/12/06 20:04:33 markd Exp $

DISTNAME=	pst-node
PKGNAME=	tex-${DISTNAME}-1.42
TEXLIVE_REV=	50215

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-node
COMMENT=	Nodes and node connections in pstricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
