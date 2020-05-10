# $NetBSD: Makefile,v 1.12 2020/05/10 04:13:25 markd Exp $

DISTNAME=	collection-langarabic
PKGNAME=	texlive-${DISTNAME}-2020pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	54405

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Arabic TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend alkalami
# depend alpha-persian
# depend amiri
DEPENDS+=	tex-arabi-[0-9]*:../../print/tex-arabi
# depend arabi-add
# depend arabluatex
DEPENDS+=	tex-arabtex-[0-9]*:../../print/tex-arabtex
# depend bidi
# depend bidihl
# depend dad
# depend ghab
DEPENDS+=	tex-hyphen-arabic-[0-9]*:../../print/tex-hyphen-arabic
DEPENDS+=	tex-hyphen-farsi-[0-9]*:../../print/tex-hyphen-farsi
# depend imsproc
# depend kurdishlipsum
# lshort-persian is documentation only
# depend luabidi
# depend na-box
# depend persian-bib
# depend sexam
# depend simurgh
# depend tram
# depend xepersian
# depend xepersian-hm

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
