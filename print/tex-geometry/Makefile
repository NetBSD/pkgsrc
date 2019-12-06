# $NetBSD: Makefile,v 1.8 2019/12/06 20:21:30 markd Exp $

DISTNAME=	geometry
PKGNAME=	tex-${DISTNAME}-5.8
TEXLIVE_REV=	47638

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/geometry
COMMENT=	Flexible and complete interface to document dimensions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
