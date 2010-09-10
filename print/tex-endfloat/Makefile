# $NetBSD: Makefile,v 1.1.1.1 2010/09/10 22:03:19 minskim Exp $

DISTNAME=	endfloat
PKGNAME=	tex-${DISTNAME}-2.4i
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Move floats to the end with markers where they belong

CONFLICTS+=	teTeX-texmf<=3.0nb27
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
