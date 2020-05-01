# $NetBSD: Makefile,v 1.10 2020/05/01 02:30:50 markd Exp $

DISTNAME=	geometry
PKGNAME=	tex-${DISTNAME}-5.9
TEXLIVE_REV=	54080

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/geometry
COMMENT=	Flexible and complete interface to document dimensions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
