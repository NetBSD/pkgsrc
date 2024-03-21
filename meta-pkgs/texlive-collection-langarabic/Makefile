# $NetBSD: Makefile,v 1.22 2024/03/21 20:00:52 markd Exp $

DISTNAME=	collection-langarabic
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	69111

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
DEPENDS+=	tex-arabluatex-[0-9]*:../../print/tex-arabluatex
DEPENDS+=	tex-arabtex-[0-9]*:../../print/tex-arabtex
DEPENDS+=	tex-bidi-[0-9]*:../../print/tex-bidi
DEPENDS+=	tex-bidihl-[0-9]*:../../print/tex-bidihl
DEPENDS+=	tex-dad-[0-9]*:../../print/tex-dad
DEPENDS+=	tex-ghab-[0-9]*:../../print/tex-ghab
DEPENDS+=	tex-hvarabic-[0-9]*:../../print/tex-hvarabic
DEPENDS+=	tex-hyphen-arabic-[0-9]*:../../print/tex-hyphen-arabic
DEPENDS+=	tex-hyphen-farsi-[0-9]*:../../print/tex-hyphen-farsi
DEPENDS+=	tex-imsproc-[0-9]*:../../print/tex-imsproc
# depend iran-bibtex
# depend khatalmaqala
DEPENDS+=	tex-kurdishlipsum-[0-9]*:../../print/tex-kurdishlipsum
# lshort-persian is documentation only
DEPENDS+=	tex-luabidi-[0-9]*:../../print/tex-luabidi
DEPENDS+=	tex-na-box-[0-9]*:../../print/tex-na-box
# depend parsimatn
# depend parsinevis
DEPENDS+=	tex-persian-bib-[0-9]*:../../print/tex-persian-bib
DEPENDS+=	tex-quran-[0-9]*:../../print/tex-quran
DEPENDS+=	tex-sexam-[0-9]*:../../print/tex-sexam
DEPENDS+=	tex-simurgh-[0-9]*:../../print/tex-simurgh
DEPENDS+=	tex-texnegar-[0-9]*:../../print/tex-texnegar
DEPENDS+=	tex-tram-[0-9]*:../../print/tex-tram
DEPENDS+=	tex-xepersian-[0-9]*:../../print/tex-xepersian
DEPENDS+=	tex-xepersian-hm-[0-9]*:../../print/tex-xepersian-hm
# xindy-persian is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
