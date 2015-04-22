# $NetBSD: Makefile,v 1.3 2015/04/22 10:21:46 markd Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-20130512
TEXLIVE_REV=	30449

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Customising captions in floating environments
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb19
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
