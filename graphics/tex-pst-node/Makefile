# $NetBSD: Makefile,v 1.9 2020/01/18 23:32:31 rillig Exp $

DISTNAME=	pst-node
PKGNAME=	tex-${DISTNAME}-1.42
TEXLIVE_REV=	50215

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-node
COMMENT=	Nodes and node connections in pstricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
