# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:21 markd Exp $

DISTNAME=	subfig
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Figures broken into subfigures
LICENSE=	lppl-1.3c

DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
