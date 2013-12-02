# $NetBSD: Makefile,v 1.2 2013/12/02 19:47:56 minskim Exp $

DISTNAME=	euro
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	22191

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Provide Euro values for national currency amounts

DEPENDS+=	tex-fp-[0-9]*:../../math/tex-fp
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
