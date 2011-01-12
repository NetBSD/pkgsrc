# $NetBSD: Makefile,v 1.1.1.1 2011/01/12 16:36:05 minskim Exp $

DISTNAME=	datetime
PKGNAME=	tex-${DISTNAME}-2.58
TEXLIVE_REV=	19834

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Change format of \today with commands for current time

DEPENDS+=	tex-fmtcount-[0-9]*:../../print/tex-fmtcount
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
