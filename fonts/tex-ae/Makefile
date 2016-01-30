# $NetBSD: Makefile,v 1.3 2016/01/30 04:56:40 markd Exp $
# TeX Live Revision 15878

DISTNAME=	ae
PKGNAME=	tex-${DISTNAME}-1.4

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Virtual fonts for T1 encoded CMR-fonts
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
