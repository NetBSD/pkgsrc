# $NetBSD: Makefile,v 1.8 2015/04/23 11:45:27 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.16
TEXLIVE_REV=	36264

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
