# $NetBSD: Makefile,v 1.3 2019/12/06 19:29:37 markd Exp $

DISTNAME=	bera
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20031

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bera fonts

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEX_MAP_FILES+=	bera.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
