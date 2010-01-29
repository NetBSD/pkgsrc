# $NetBSD: Makefile,v 1.3 2010/01/29 01:54:26 minskim Exp $
# TeX Live Revision 15878

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.141592653

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The Plain TeX format

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-misc-[0-9]*:../../print/tex-misc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
