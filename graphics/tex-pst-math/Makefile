# $NetBSD: Makefile,v 1.5 2019/12/06 20:04:33 markd Exp $

DISTNAME=	pst-math
PKGNAME=	tex-${DISTNAME}-0.65
TEXLIVE_REV=	49425

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-math
COMMENT=	Enhancement of PostScript math operators to use with pstricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
