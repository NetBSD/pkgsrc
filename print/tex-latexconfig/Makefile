# $NetBSD: Makefile,v 1.14 2019/12/06 20:21:50 markd Exp $

DISTNAME=	latexconfig
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40274

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files used to generate LaTeX formats

CONFLICTS+=	tex-bin-latex<2008.12778nb5

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
