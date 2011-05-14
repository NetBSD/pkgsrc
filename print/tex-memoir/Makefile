# $NetBSD: Makefile,v 1.6 2011/05/14 22:11:08 minskim Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-3.6gpl6.0g
TEXLIVE_REV=	21638

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Typeset fiction, non-fiction and mathematical books

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
