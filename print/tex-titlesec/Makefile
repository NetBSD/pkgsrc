# $NetBSD: Makefile,v 1.3 2010/09/14 00:18:20 minskim Exp $

DISTNAME=	titlesec
PKGNAME=	tex-${DISTNAME}-2.8
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Select alternative section titles

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
