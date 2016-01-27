# $NetBSD: Makefile,v 1.5 2016/01/27 10:13:21 markd Exp $

DISTNAME=	moreverb
PKGNAME=	tex-${DISTNAME}-2.3a
TEXLIVE_REV=	22126

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended verbatim
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
