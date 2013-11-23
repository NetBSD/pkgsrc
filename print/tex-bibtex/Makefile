# $NetBSD: Makefile,v 1.6 2013/11/23 00:04:04 minskim Exp $

DISTNAME=	bibtex
PKGNAME=	tex-${DISTNAME}-0.99d
PKGREVISION=	1
TEXLIVE_REV=	29764

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Reference management software for LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb15
DEPENDS+=	web2c>=2013:../../print/web2c

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
