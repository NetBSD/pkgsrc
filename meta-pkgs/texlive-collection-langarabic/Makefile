# $NetBSD: Makefile,v 1.18 2022/08/19 20:11:22 wiz Exp $

DISTNAME=	collection-langarabic
PKGNAME=	texlive-${DISTNAME}-2022pre3
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
# depend imsproc
# depend kurdishlipsum
# lshort-persian is documentation only
# depend luabidi
# depend na-box
# depend persian-bib
DEPENDS+=	tex-quran-[0-9]*:../../print/tex-quran
# depend sexam
# depend simurgh
# depend texnegar
# depend tram
# depend xepersian
# depend xepersian-hm
# xindy-persian is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
