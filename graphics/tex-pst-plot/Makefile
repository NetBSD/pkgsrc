# $NetBSD: Makefile,v 1.9 2019/01/26 02:41:05 markd Exp $

DISTNAME=	pst-plot
PKGNAME=	tex-${DISTNAME}-1.91
TEXLIVE_REV=	48526

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-plot
COMMENT=	Plot data using PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
