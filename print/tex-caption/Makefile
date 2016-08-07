# $NetBSD: Makefile,v 1.5 2016/08/07 09:09:37 markd Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-20160522
TEXLIVE_REV=	41409

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/caption
COMMENT=	Customising captions in floating environments
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb19
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
