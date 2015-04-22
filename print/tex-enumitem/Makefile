# $NetBSD: Makefile,v 1.4 2015/04/22 22:15:41 markd Exp $

DISTNAME=	enumitem
PKGNAME=	tex-${DISTNAME}-3.5.2
TEXLIVE_REV=	24146

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Control layout of itemize, enumerate, and description

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
