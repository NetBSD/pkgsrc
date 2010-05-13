# $NetBSD: Makefile,v 1.2 2010/05/13 08:40:44 minskim Exp $

DISTNAME=	moreverb
PKGNAME=	tex-${DISTNAME}-2.3
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended verbatim

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
