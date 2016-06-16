# $NetBSD: Makefile,v 1.11 2016/06/16 04:06:10 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.20
TEXLIVE_REV=	41038

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/koma-script
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
