# $NetBSD: Makefile,v 1.5 2016/01/30 03:26:05 markd Exp $

DISTNAME=	abc
PKGNAME=	tex-${DISTNAME}-1.0
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Support ABC music notation in LaTeX
LICENSE=	lppl-1.2

DEPENDS+=	abcm2ps-[0-9]*:../../print/abcm2ps
DEPENDS+=	ps2eps-[0-9]*:../../graphics/ps2eps
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-oberdiek>=2009nb2:../../print/tex-oberdiek
DEPENDS+=	tex-tools>=2010:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
