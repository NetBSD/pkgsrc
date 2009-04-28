# $NetBSD: Makefile,v 1.1.1.1 2009/04/28 19:51:00 minskim Exp $
# TeX Live Revision 9143

DISTNAME=	etex-pkg
PKGNAME=	tex-${DISTNAME}-2.0

MAINTAINER=	minskim@NetBSD.org
COMMENT=	E-TeX support package

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
