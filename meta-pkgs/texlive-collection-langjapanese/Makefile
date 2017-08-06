# $NetBSD: Makefile,v 1.8 2017/08/06 12:27:09 markd Exp $

DISTNAME=	collection-langjapanese
PKGNAME=	texlive-${DISTNAME}-2017pre3
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	44725

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Japanese TeX packages

DEPENDS+=	texlive-collection-langcjk-[0-9]*:../../meta-pkgs/texlive-collection-langcjk

# depend babel-japanese
# depend bxbase
# depend bxcjkjatype
# depend bxjalipsum
# depend bxjaprnind
# depend bxjscls
# depend bxorigcapt
# depend convbkmk
# depend ifptex
DEPENDS+=	tex-ipaex-[0-9]*:../../fonts/tex-ipaex
DEPENDS+=	tex-japanese-otf-[0-9]*:../../fonts/tex-japanese-otf
# depend japanese-otf-uptex
# depend jlreq
DEPENDS+=	tex-jsclasses-[0-9]*:../../print/tex-jsclasses
# lshort-japanese is documentation only
# depend luatexja
# mendex-doc is documentation only
DEPENDS+=	tex-pbibtex-base-[0-9]*:../../print/tex-pbibtex-base
DEPENDS+=	tex-platex-[0-9]*:../../print/tex-platex
# depend platex-tools
# platexcheat is documentation only
DEPENDS+=	tex-ptex-[0-9]*:../../print/tex-ptex
DEPENDS+=	tex-ptex-base-[0-9]*:../../print/tex-ptex-base
DEPENDS+=	tex-ptex-fonts-[0-9]*:../../fonts/tex-ptex-fonts
DEPENDS+=	tex-ptex-fontmaps-[0-9]*:../../fonts/tex-ptex-fontmaps
# depend ptex2pdf
# depend pxbase
# depend pxchfon
# depend pxcjkcat
# depend pxjahyper
# depend pxrubrica
# depend pxufont
# depend uplatex
# uptex is documentation only
# depend uptex-base
# depend uptex-fonts
DEPENDS+=	tex-wadalab-[0-9]*:../../fonts/tex-wadalab
# depend zxjafbfont
# depend zxjatype

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
