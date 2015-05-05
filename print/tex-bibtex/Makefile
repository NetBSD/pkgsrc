# $NetBSD: Makefile,v 1.7 2015/05/05 16:33:49 wiz Exp $

DISTNAME=	bibtex
PKGNAME=	tex-${DISTNAME}-0.99d
PKGREVISION=	2
TEXLIVE_REV=	33736

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/bibtex
COMMENT=	Reference management software for LaTeX
#LICENSE=	knuth

CONFLICTS+=	teTeX-texmf<=3.0nb15
DEPENDS+=	web2c>=2013:../../print/web2c
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
