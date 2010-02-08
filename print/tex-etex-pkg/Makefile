# $NetBSD: Makefile,v 1.2 2010/02/08 04:03:06 minskim Exp $
# TeX Live Revision 15878

DISTNAME=	etex-pkg
PKGNAME=	tex-${DISTNAME}-2.0

MAINTAINER=	minskim@NetBSD.org
COMMENT=	E-TeX support package

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
