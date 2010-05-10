# $NetBSD: Makefile,v 1.1.1.1 2010/05/10 22:39:01 minskim Exp $

DISTNAME=	lh
PKGNAME=	tex-${DISTNAME}-3.5g
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Cyrillic fonts that support LaTeX standard encodings

CONFLICTS+=	teTeX-texmf<=3.0nb24
DEPENDS+=	tex-ec>=1.0:../../fonts/tex-ec

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
