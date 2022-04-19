# $NetBSD: Makefile,v 1.17 2022/04/19 03:17:27 markd Exp $

DISTNAME=	collection-langarabic
PKGNAME=	texlive-${DISTNAME}-2022pre2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	59594

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Arabic TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend alkalami
# depend alpha-persian
# depend amiri
DEPENDS+=	tex-arabi-[0-9]*:../../print/tex-arabi
# depend arabi-add
# depend arabic-book
# depend arabluatex
DEPENDS+=	tex-arabtex-[0-9]*:../../print/tex-arabtex
DEPENDS+=	tex-bidi-[0-9]*:../../print/tex-bidi
# depend bidihl
# depend dad
# depend ghab
# depend hvarabic
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
