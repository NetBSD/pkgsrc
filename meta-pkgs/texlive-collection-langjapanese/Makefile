# $NetBSD: Makefile,v 1.3 2016/06/16 04:03:15 markd Exp $

DISTNAME=	collection-langjapanese
PKGNAME=	texlive-${DISTNAME}-2016pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	41002

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Japanese TeX packages

DEPENDS+=	texlive-collection-langcjk-[0-9]*:../../meta-pkgs/texlive-collection-langcjk

# depend bxbase
# depend bxcjkjatype
# depend bxjscls
# depend convbkmk
DEPENDS+=	tex-ipaex-[0-9]*:../../fonts/tex-ipaex
DEPENDS+=	tex-japanese-[0-9]*:../../print/tex-japanese
DEPENDS+=	tex-japanese-otf-[0-9]*:../../fonts/tex-japanese-otf
# depend japanese-otf-uptex
# depend jfontmaps
DEPENDS+=	tex-jsclasses-[0-9]*:../../print/tex-jsclasses
# lshort-japanese is documentation only
# depend luatexja
DEPENDS+=	tex-pbibtex-base-[0-9]*:../../print/tex-pbibtex-base
# depend platex
DEPENDS+=	tex-ptex-[0-9]*:../../print/tex-ptex
DEPENDS+=	tex-ptex-base-[0-9]*:../../print/tex-ptex-base
DEPENDS+=	tex-ptex-fonts-[0-9]*:../../fonts/tex-ptex-fonts
# depend ptex2pdf
# depend pxbase
# depend pxchfon
# depend pxcjkcat
# depend pxjahyper
# depend pxrubrica
# depend uplatex
# depend uptex
# depend uptex-base
# depend uptex-fonts
DEPENDS+=	tex-wadalab-[0-9]*:../../fonts/tex-wadalab
# depend zxjafbfont
# depend zxjatype

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
