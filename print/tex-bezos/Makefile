# $NetBSD: Makefile,v 1.2 2015/04/22 10:15:29 markd Exp $

DISTNAME=	bezos
PKGNAME=	tex-${DISTNAME}-25507
TEXLIVE_REV=	25507

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Packages by Javier Bezos

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
