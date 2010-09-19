# $NetBSD: Makefile,v 1.4 2010/09/19 23:17:17 minskim Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-3.6fpl6.0g
TEXLIVE_REV=	19776

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Typeset fiction, non-fiction and mathematical books

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
