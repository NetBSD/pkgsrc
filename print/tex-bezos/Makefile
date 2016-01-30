# $NetBSD: Makefile,v 1.3 2016/01/30 03:26:08 markd Exp $

DISTNAME=	bezos
PKGNAME=	tex-${DISTNAME}-25507
TEXLIVE_REV=	25507

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Packages by Javier Bezos
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
