# $NetBSD: Makefile,v 1.8 2015/06/14 12:50:04 markd Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-3.7c.37021
TEXLIVE_REV=	37021

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/memoir
COMMENT=	Typeset fiction, non-fiction and mathematical books
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
