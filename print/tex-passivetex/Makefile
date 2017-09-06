# $NetBSD: Makefile,v 1.9 2017/09/06 10:40:32 wiz Exp $

DISTNAME=	passivetex
PKGNAME=	tex-${DISTNAME}-1.25
PKGREVISION=	2
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
#HOMEPAGE=	http://www.tei-c.org.uk/Software/passivetex/
COMMENT=	Support package for XML/SGML typesetting

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-marvosym-[0-9]*:../../fonts/tex-marvosym
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-rotating-[0-9]*:../../print/tex-rotating
DEPENDS+=	tex-tipa-[0-9]*:../../fonts/tex-tipa
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-url>=3.2:../../print/tex-url
DEPENDS+=	tex-xmltex-[0-9]*:../../textproc/tex-xmltex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
