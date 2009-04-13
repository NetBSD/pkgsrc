# $NetBSD: Makefile,v 1.1.1.1 2009/04/13 07:19:45 minskim Exp $
# TeX Live Revision 9267

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.14159265

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The Plain TeX format

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-misc-[0-9]*:../../print/tex-misc

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
