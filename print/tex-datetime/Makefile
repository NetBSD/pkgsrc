# $NetBSD: Makefile,v 1.2 2015/04/22 10:42:01 markd Exp $

DISTNAME=	datetime
PKGNAME=	tex-${DISTNAME}-2.60
TEXLIVE_REV=	36650

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Change format of \today with commands for current time
LICENSE=	lppl-1.3c

DEPENDS+=	tex-fmtcount-[0-9]*:../../print/tex-fmtcount
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
