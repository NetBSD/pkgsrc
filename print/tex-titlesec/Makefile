# $NetBSD: Makefile,v 1.4 2015/04/25 04:57:52 markd Exp $

DISTNAME=	titlesec
PKGNAME=	tex-${DISTNAME}-2.10.0
TEXLIVE_REV=	24852

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Select alternative section titles

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
