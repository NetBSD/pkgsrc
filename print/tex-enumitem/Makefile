# $NetBSD: Makefile,v 1.3 2010/09/14 00:18:16 minskim Exp $

DISTNAME=	enumitem
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Control layout of itemize, enumerate, and description

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
