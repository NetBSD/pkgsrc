# $NetBSD: Makefile,v 1.7 2015/04/23 12:17:14 markd Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-3.7c
TEXLIVE_REV=	36449

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Typeset fiction, non-fiction and mathematical books

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
