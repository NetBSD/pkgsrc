# $NetBSD: Makefile,v 1.4 2020/05/02 02:50:29 markd Exp $

DISTNAME=	metalogo
PKGNAME=	tex-${DISTNAME}-0.12
PKGREVISION=	1
TEXLIVE_REV=	18611

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended TeX logo macros
LICENSE=	lppl-1.3c

DEPENDS+=	tex-fontspec>=2.1e:../../fonts/tex-fontspec
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
