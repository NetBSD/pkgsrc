# $NetBSD: Makefile,v 1.5 2009/05/25 05:24:00 minskim Exp $
# TeX Live Revision 9324

DISTNAME=	passivetex
PKGNAME=	tex-${DISTNAME}-1.25

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tei-c.org.uk/Software/passivetex/
COMMENT=	Support package for XML/SGML typesetting

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-ltxmisc-[0-9]*:../../print/tex-ltxmisc
DEPENDS+=	tex-marvosym-[0-9]*:../../fonts/tex-marvosym
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-rotating-[0-9]*:../../print/tex-rotating
DEPENDS+=	tex-tipa-[0-9]*:../../fonts/tex-tipa
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xmltex-[0-9]*:../../textproc/tex-xmltex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
