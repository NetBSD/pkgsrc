# $NetBSD: Makefile,v 1.12 2022/04/10 06:26:51 markd Exp $

DISTNAME=	pst-plot
PKGNAME=	tex-${DISTNAME}-1.93
TEXLIVE_REV=	60620

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-plot
COMMENT=	Plot data using PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
