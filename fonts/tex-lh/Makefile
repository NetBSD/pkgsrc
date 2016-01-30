# $NetBSD: Makefile,v 1.2 2016/01/30 04:56:43 markd Exp $

DISTNAME=	lh
PKGNAME=	tex-${DISTNAME}-3.5g
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Cyrillic fonts that support LaTeX standard encodings
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb24
DEPENDS+=	tex-ec>=1.0:../../fonts/tex-ec

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
