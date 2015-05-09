# $NetBSD: Makefile,v 1.2 2015/05/09 23:31:53 markd Exp $

DISTNAME=	collection-langjapanese
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	33790

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
DEPENDS+=	tex-ptex-[0-9]*:../../print/tex-ptex
# depend ptex2pdf
# depend pxbase
# depend pxchfon
# depend pxcjkcat
# depend pxjahyper
# depend pxrubrica
# depend uptex
DEPENDS+=	tex-wadalab-[0-9]*:../../fonts/tex-wadalab
# depend zxjafbfont
# depend zxjatype

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
