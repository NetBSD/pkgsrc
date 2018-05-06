# $NetBSD: Makefile,v 1.6 2018/05/06 04:00:15 markd Exp $

DISTNAME=	geometry
PKGNAME=	tex-${DISTNAME}-5.7
TEXLIVE_REV=	47106

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/geometry
COMMENT=	Flexible and complete interface to document dimensions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
