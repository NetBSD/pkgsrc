# $NetBSD: Makefile,v 1.12 2016/08/07 09:09:38 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.21
TEXLIVE_REV=	41508

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/koma-script
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
