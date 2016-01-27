# $NetBSD: Makefile,v 1.5 2016/01/27 10:53:21 markd Exp $

DISTNAME=	enumitem
PKGNAME=	tex-${DISTNAME}-3.5.2
TEXLIVE_REV=	24146

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Control layout of itemize, enumerate, and description
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
