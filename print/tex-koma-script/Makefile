# $NetBSD: Makefile,v 1.24 2022/04/14 01:55:51 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.35
TEXLIVE_REV=	62874

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/koma-script
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
