# $NetBSD: Makefile,v 1.3 2010/05/10 20:47:03 minskim Exp $

DISTNAME=	natbib
PKGNAME=	tex-${DISTNAME}-8.31a
TEXLIVE_REV=	16643

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible bibliography support for BibTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	web2c-[0-9]*:../../print/web2c

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
