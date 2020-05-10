# $NetBSD: Makefile,v 1.16 2020/05/10 12:52:42 markd Exp $

DISTNAME=	collection-langjapanese
PKGNAME=	texlive-${DISTNAME}-2020pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	54894

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Japanese TeX packages

DEPENDS+=	texlive-collection-langcjk-[0-9]*:../../meta-pkgs/texlive-collection-langcjk

# depend ascmac
# depend babel-japanese
# depend bxbase
# depend bxcjkjatype
# depend bxghost
# depend bxjaholiday
# depend bxjalipsum
# depend bxjaprnind
# depend bxjatoucs
# depend bxjscls
# depend bxorigcapt
# depend bxwareki
# depend convbkmk
# depend endnotesj
# depend gentombow
DEPENDS+=	tex-haranoaji-[0-9]*:../../fonts/tex-haranoaji
# depend haranoaji-extra
# depend ifptex
# depend ifxptex
DEPENDS+=	tex-ipaex-[0-9]*:../../fonts/tex-ipaex
DEPENDS+=	tex-japanese-otf-[0-9]*:../../fonts/tex-japanese-otf
# depend japanese-otf-uptex
# depend jlreq
# depend jlreq-deluxe
DEPENDS+=	tex-jsclasses-[0-9]*:../../print/tex-jsclasses
# lshort-japanese is documentation only
# depend luatexja
# mendex-doc is documentation only
# depend morisawa
DEPENDS+=	tex-pbibtex-base-[0-9]*:../../print/tex-pbibtex-base
DEPENDS+=	tex-platex-[0-9]*:../../print/tex-platex
# depend platex-tools
# platexcheat is documentation only
# depend plautopatch
DEPENDS+=	tex-ptex-[0-9]*:../../print/tex-ptex
DEPENDS+=	tex-ptex-base-[0-9]*:../../print/tex-ptex-base
DEPENDS+=	tex-ptex-fontmaps-[0-9]*:../../fonts/tex-ptex-fontmaps
DEPENDS+=	tex-ptex-fonts-[0-9]*:../../fonts/tex-ptex-fonts
# depend ptex-manual
# depend ptex2pdf
# depend pxbase
# depend pxchfon
# depend pxcjkcat
# depend pxjahyper
# depend pxjodel
# depend pxrubrica
# depend pxufont
# depend texlive-ja
# depend uplatex
# uptex is documentation only
# depend uptex-base
# depend uptex-fonts
DEPENDS+=	tex-wadalab-[0-9]*:../../fonts/tex-wadalab
# depend zxjafbfont
# depend zxjatype

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
