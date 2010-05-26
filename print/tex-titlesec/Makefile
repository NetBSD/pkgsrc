# $NetBSD: Makefile,v 1.2 2010/05/26 03:59:06 minskim Exp $

DISTNAME=	titlesec
PKGNAME=	tex-${DISTNAME}-2.8
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Select alternative section titles

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
