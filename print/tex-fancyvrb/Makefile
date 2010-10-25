# $NetBSD: Makefile,v 1.3 2010/10/25 07:04:38 minskim Exp $

DISTNAME=	fancyvrb
PKGNAME=	tex-${DISTNAME}-2.8
TEXLIVE_REV=	18492

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Sophisticated verbatim text

CONFLICTS+=	teTeX-texmf<=3.0nb20
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
