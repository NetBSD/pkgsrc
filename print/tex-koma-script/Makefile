# $NetBSD: Makefile,v 1.13 2017/06/21 08:28:41 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.23
TEXLIVE_REV=	44226

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/koma-script
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
