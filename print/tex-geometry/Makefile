# $NetBSD: Makefile,v 1.9 2020/01/18 23:34:13 rillig Exp $

DISTNAME=	geometry
PKGNAME=	tex-${DISTNAME}-5.8
TEXLIVE_REV=	47638

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/geometry
COMMENT=	Flexible and complete interface to document dimensions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
