# $NetBSD: Makefile,v 1.10 2015/08/02 13:10:05 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.18
TEXLIVE_REV=	37734

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/koma-script
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
