# $NetBSD: Makefile,v 1.19 2022/08/20 23:33:41 wiz Exp $

DISTNAME=	collection-langarabic
PKGNAME=	texlive-${DISTNAME}-2022pre4
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	59594

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Arabic TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-alkalami-[0-9]*:../../fonts/tex-alkalami
DEPENDS+=	tex-alpha-persian-[0-9]*:../../print/tex-alpha-persian
DEPENDS+=	tex-amiri-[0-9]*:../../fonts/tex-amiri
DEPENDS+=	tex-arabi-[0-9]*:../../print/tex-arabi
DEPENDS+=	tex-arabi-add-[0-9]*:../../print/tex-arabi-add
DEPENDS+=	tex-arabic-book-[0-9]*:../../print/tex-arabic-book
# depend arabluatex
DEPENDS+=	tex-arabtex-[0-9]*:../../print/tex-arabtex
DEPENDS+=	tex-bidi-[0-9]*:../../print/tex-bidi
DEPENDS+=	tex-bidihl-[0-9]*:../../print/tex-bidihl
DEPENDS+=	tex-dad-[0-9]*:../../print/tex-dad
DEPENDS+=	tex-ghab-[0-9]*:../../print/tex-ghab
DEPENDS+=	tex-hvarabic-[0-9]*:../../print/tex-hvarabic
DEPENDS+=	tex-hyphen-arabic-[0-9]*:../../print/tex-hyphen-arabic
DEPENDS+=	tex-hyphen-farsi-[0-9]*:../../print/tex-hyphen-farsi
DEPENDS+=	tex-imsproc-[0-9]*:../../print/tex-imsproc
DEPENDS+=	tex-kurdishlipsum-[0-9]*:../../print/tex-kurdishlipsum
# lshort-persian is documentation only
DEPENDS+=	tex-luabidi-[0-9]*:../../print/tex-luabidi
DEPENDS+=	tex-na-box-[0-9]*:../../print/tex-na-box
DEPENDS+=	tex-persian-bib-[0-9]*:../../print/tex-persian-bib
DEPENDS+=	tex-quran-[0-9]*:../../print/tex-quran
DEPENDS+=	tex-sexam-[0-9]*:../../print/tex-sexam
# depend simurgh
# depend texnegar
# depend tram
# depend xepersian
# depend xepersian-hm
# xindy-persian is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
