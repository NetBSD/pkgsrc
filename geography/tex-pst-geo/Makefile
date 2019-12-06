# $NetBSD: Makefile,v 1.3 2019/12/06 19:10:17 markd Exp $

DISTNAME=	pst-geo
PKGNAME=	tex-${DISTNAME}-2.06
TEXLIVE_REV=	44131

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-geo
COMMENT=	Geographical Projections
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
