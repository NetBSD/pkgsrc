# $NetBSD: Makefile,v 1.2 2009/06/09 22:20:53 minskim Exp $
# TeX Live Revision 12854

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.14159265.12854

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The Plain TeX format

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-misc-[0-9]*:../../print/tex-misc

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
