# $NetBSD: Makefile,v 1.4 2012/02/10 17:50:46 minskim Exp $

DISTNAME=	moreverb
PKGNAME=	tex-${DISTNAME}-2.3a
TEXLIVE_REV=	22126

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended verbatim

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
