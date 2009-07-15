# $NetBSD: Makefile,v 1.1.1.1 2009/07/15 20:46:03 minskim Exp $
# TeX Live Revision 10446

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-3.1j

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Customising captions in floating environments

CONFLICTS+=	teTeX-texmf<=3.0nb19
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
