# $NetBSD: Makefile,v 1.6 2017/09/06 16:49:27 wiz Exp $

DISTNAME=	pst-plot
PKGNAME=	tex-${DISTNAME}-1.79
TEXLIVE_REV=	44511

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-plot
COMMENT=	Plot data using PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
