# $NetBSD: Makefile,v 1.9 2015/06/14 12:50:03 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.17a
TEXLIVE_REV=	37384

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
