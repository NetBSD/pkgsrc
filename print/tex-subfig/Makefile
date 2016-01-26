# $NetBSD: Makefile,v 1.3 2016/01/26 11:08:59 markd Exp $

DISTNAME=	subfig
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Figures broken into subfigures
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb19
DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
