# $NetBSD: Makefile,v 1.1.1.1 2009/04/23 23:50:11 minskim Exp $
# TeX Live Revision 9734

DISTNAME=	exam
PKGNAME=	tex-${DISTNAME}-2.3

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Package for typesetting exam scripts

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
