# $NetBSD: Makefile,v 1.2 2010/02/19 18:19:44 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	carlisle
PKGNAME=	tex-${DISTNAME}-2008.7340
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX packages created by David Carlisle

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
