# $NetBSD: Makefile,v 1.1 2022/08/21 14:40:07 wiz Exp $

DISTNAME=	simurgh
PKGNAME=	tex-${DISTNAME}-0.01b
TEXLIVE_REV=	31719

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/simurgh
COMMENT=	Typeset Parsi in LuaLaTeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-auxhook-[0-9]*:../../print/tex-auxhook
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
# graphicx
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
# ifluatex
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
# makeidx
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds
DEPENDS+=	tex-microtype-[0-9]*:../../print/tex-microtype
DEPENDS+=	tex-minted-[0-9]*:../../print/tex-minted
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
# zref-abspage
DEPENDS+=	tex-zref-[0-9]*:../../print/tex-zref

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
