# $NetBSD: Makefile,v 1.27 2023/04/01 11:34:14 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.38
TEXLIVE_REV=	64685

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/koma-script
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
