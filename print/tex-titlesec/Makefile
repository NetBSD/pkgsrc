# $NetBSD: Makefile,v 1.6 2016/06/16 04:06:17 markd Exp $

DISTNAME=	titlesec
PKGNAME=	tex-${DISTNAME}-2.10.2
TEXLIVE_REV=	40129

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Select alternative section titles
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
