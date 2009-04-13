# $NetBSD: Makefile,v 1.1.1.1 2009/04/13 07:31:50 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	etex
PKGNAME=	tex-${DISTNAME}-2.1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX implementation filling the gap between TeX3 and NTS

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
