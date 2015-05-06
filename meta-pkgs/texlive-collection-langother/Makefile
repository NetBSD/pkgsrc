# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:44 markd Exp $

DISTNAME=	collection-langother
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	31014

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Other languages TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend amsldoc-vn
# depend aramaic-serto
DEPENDS+=	tex-babel-bahasa-[0-9]*:../../print/tex-babel-bahasa
DEPENDS+=	tex-babel-esperanto-[0-9]*:../../print/tex-babel-esperanto
DEPENDS+=	tex-babel-georgian-[0-9]*:../../print/tex-babel-georgian
DEPENDS+=	tex-babel-hebrew-[0-9]*:../../print/tex-babel-hebrew
DEPENDS+=	tex-babel-interlingua-[0-9]*:../../print/tex-babel-interlingua
DEPENDS+=	tex-babel-sorbian-[0-9]*:../../print/tex-babel-sorbian
DEPENDS+=	tex-babel-thai-[0-9]*:../../print/tex-babel-thai
DEPENDS+=	tex-babel-vietnamese-[0-9]*:../../print/tex-babel-vietnamese
# depend cjhebrew
# depend ctib
DEPENDS+=	tex-fonts-tlwg-[0-9]*:../../fonts/tex-fonts-tlwg
# depend hyphen-afrikaans
DEPENDS+=	tex-hyphen-coptic-[0-9]*:../../print/tex-hyphen-coptic
DEPENDS+=	tex-hyphen-esperanto-[0-9]*:../../print/tex-hyphen-esperanto
# depend hyphen-georgian
DEPENDS+=	tex-hyphen-indonesian-[0-9]*:../../print/tex-hyphen-indonesian
DEPENDS+=	tex-hyphen-interlingua-[0-9]*:../../print/tex-hyphen-interlingua
# depend hyphen-thai
# depend hyphen-turkmen
# depend lshort-thai
# depend lshort-vietnamese
# depend ntheorem-vn
DEPENDS+=	tex-vntex-[0-9]*:../../print/tex-vntex

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
