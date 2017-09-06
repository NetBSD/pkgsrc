# $NetBSD: Makefile,v 1.4 2017/09/06 16:49:44 wiz Exp $

DISTNAME=	subfig
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Figures broken into subfigures
LICENSE=	lppl-1.3c

DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
