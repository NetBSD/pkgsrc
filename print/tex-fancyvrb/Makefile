# $NetBSD: Makefile,v 1.4 2016/01/27 10:42:26 markd Exp $

DISTNAME=	fancyvrb
PKGNAME=	tex-${DISTNAME}-2.8
TEXLIVE_REV=	18492

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Sophisticated verbatim text
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb20
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
