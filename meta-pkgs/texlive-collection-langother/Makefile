# $NetBSD: Makefile,v 1.18 2024/03/21 20:00:54 markd Exp $

DISTNAME=	collection-langother
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	68719

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Other languages TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend aalok
# depend akshar
# amsldoc-vn is documentation only
DEPENDS+=	tex-aramaic-serto-[0-9]*:../../fonts/tex-aramaic-serto
# depend babel-azerbaijani
DEPENDS+=	tex-babel-esperanto-[0-9]*:../../print/tex-babel-esperanto
DEPENDS+=	tex-babel-georgian-[0-9]*:../../print/tex-babel-georgian
DEPENDS+=	tex-babel-hebrew-[0-9]*:../../print/tex-babel-hebrew
# depend babel-indonesian
DEPENDS+=	tex-babel-interlingua-[0-9]*:../../print/tex-babel-interlingua
# depend babel-malay
DEPENDS+=	tex-babel-sorbian-[0-9]*:../../print/tex-babel-sorbian
DEPENDS+=	tex-babel-thai-[0-9]*:../../print/tex-babel-thai
DEPENDS+=	tex-babel-vietnamese-[0-9]*:../../print/tex-babel-vietnamese
# depend bangla
# depend bangtex
# depend bengali
# depend burmese
# depend chhaya
DEPENDS+=	tex-cjhebrew-[0-9]*:../../fonts/tex-cjhebrew
DEPENDS+=	tex-ctib-[0-9]*:../../print/tex-ctib
# depend culmus
# depend ebong
DEPENDS+=	tex-ethiop-[0-9]*:../../print/tex-ethiop
DEPENDS+=	tex-ethiop-t1-[0-9]*:../../fonts/tex-ethiop-t1
DEPENDS+=	tex-fc-[0-9]*:../../fonts/tex-fc
DEPENDS+=	tex-fonts-tlwg-[0-9]*:../../fonts/tex-fonts-tlwg
# depend hebrew-fonts
# hindawi-latex-template is documentation only
DEPENDS+=	tex-hyphen-afrikaans-[0-9]*:../../print/tex-hyphen-afrikaans
DEPENDS+=	tex-hyphen-armenian-[0-9]*:../../print/tex-hyphen-armenian
DEPENDS+=	tex-hyphen-coptic-[0-9]*:../../print/tex-hyphen-coptic
DEPENDS+=	tex-hyphen-esperanto-[0-9]*:../../print/tex-hyphen-esperanto
DEPENDS+=	tex-hyphen-ethiopic-[0-9]*:../../print/tex-hyphen-ethiopic
DEPENDS+=	tex-hyphen-georgian-[0-9]*:../../print/tex-hyphen-georgian
DEPENDS+=	tex-hyphen-indic-[0-9]*:../../print/tex-hyphen-indic
DEPENDS+=	tex-hyphen-indonesian-[0-9]*:../../print/tex-hyphen-indonesian
DEPENDS+=	tex-hyphen-interlingua-[0-9]*:../../print/tex-hyphen-interlingua
DEPENDS+=	tex-hyphen-sanskrit-[0-9]*:../../print/tex-hyphen-sanskrit
DEPENDS+=	tex-hyphen-thai-[0-9]*:../../print/tex-hyphen-thai
DEPENDS+=	tex-hyphen-turkmen-[0-9]*:../../print/tex-hyphen-turkmen
# latex-mr is documentation only
# depend latexbangla
# depend latino-sine-flexione
# lshort-thai is documentation only
# lshort-vietnamese is documentation only
# depend marathi
# ntheorem-vn is documentation only
# depend padauk
# depend quran-bn
# depend quran-id
# depend quran-ur
# depend sanskrit
# depend sanskrit-t1
# depend thaienum
# depend thaispec
# depend unicode-alphabets
# depend velthuis
DEPENDS+=	tex-vntex-[0-9]*:../../print/tex-vntex
# depend wnri
# depend wnri-latex
# depend xetex-devanagari

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
