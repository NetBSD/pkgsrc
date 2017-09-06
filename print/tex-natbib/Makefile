# $NetBSD: Makefile,v 1.6 2017/09/06 16:49:41 wiz Exp $

DISTNAME=	natbib
PKGNAME=	tex-${DISTNAME}-8.31b
TEXLIVE_REV=	20668

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible bibliography support for BibTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	web2c-[0-9]*:../../print/web2c

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
