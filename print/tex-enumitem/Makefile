# $NetBSD: Makefile,v 1.1.1.1 2009/07/09 22:52:06 minskim Exp $
# TeX Live Revision 9740

DISTNAME=	enumitem
PKGNAME=	tex-${DISTNAME}-2.1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Control layout of itemize, enumerate, and description

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
