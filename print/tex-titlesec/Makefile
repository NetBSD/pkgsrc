# $NetBSD: Makefile,v 1.5 2016/01/26 10:53:51 markd Exp $

DISTNAME=	titlesec
PKGNAME=	tex-${DISTNAME}-2.10.0
TEXLIVE_REV=	24852

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Select alternative section titles
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
