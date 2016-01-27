# $NetBSD: Makefile,v 1.5 2016/01/27 10:00:25 markd Exp $

DISTNAME=	natbib
PKGNAME=	tex-${DISTNAME}-8.31b
TEXLIVE_REV=	20668

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible bibliography support for BibTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	web2c-[0-9]*:../../print/web2c

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
