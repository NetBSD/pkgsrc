# $NetBSD: Makefile,v 1.10 2017/09/06 16:29:25 wiz Exp $

DISTNAME=	ptex
PKGNAME=	tex-${DISTNAME}-3.2pl41220
PKGREVISION=	4
TEXLIVE_REV=	41220

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX system for publishing in Japanese

CONFLICTS+=	ja-ptex-bin-[0-9]*
DEPENDS+=	tex-adobemapping-[0-9]*:../../fonts/tex-adobemapping
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-ipaex-[0-9]*:../../fonts/tex-ipaex
DEPENDS+=	tex-japanese-otf-[0-9]*:../../fonts/tex-japanese-otf
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-pbibtex-base-[0-9]*:../../print/tex-pbibtex-base
DEPENDS+=	tex-ptex-base-[0-9]*:../../print/tex-ptex-base
DEPENDS+=	tex-ptex-fonts-[0-9]*:../../fonts/tex-ptex-fonts
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
# switch.def
DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	web2c>=2010nb5:../../print/web2c

TEX_FORMATS+=		"ptex ptex - ptex.ini\\neptex eptex language.def *eptex.ini\\n"
TEX_KANJIMAP_FILES+=	morisawa.map

.include "../../print/texlive/package.mk"

.include "../../mk/bsd.pkg.mk"
