# $NetBSD: Makefile,v 1.7 2019/01/23 10:19:36 markd Exp $

DISTNAME=	geometry
PKGNAME=	tex-${DISTNAME}-5.8
TEXLIVE_REV=	47638

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/geometry
COMMENT=	Flexible and complete interface to document dimensions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
