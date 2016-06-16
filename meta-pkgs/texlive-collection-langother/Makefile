# $NetBSD: Makefile,v 1.6 2016/06/16 04:03:15 markd Exp $

DISTNAME=	collection-langother
PKGNAME=	texlive-${DISTNAME}-2016
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	31014

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Other languages TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# amsldoc-vn is documentation only
DEPENDS+=	tex-aramaic-serto-[0-9]*:../../fonts/tex-aramaic-serto
DEPENDS+=	tex-babel-bahasa-[0-9]*:../../print/tex-babel-bahasa
DEPENDS+=	tex-babel-esperanto-[0-9]*:../../print/tex-babel-esperanto
DEPENDS+=	tex-babel-georgian-[0-9]*:../../print/tex-babel-georgian
DEPENDS+=	tex-babel-hebrew-[0-9]*:../../print/tex-babel-hebrew
DEPENDS+=	tex-babel-interlingua-[0-9]*:../../print/tex-babel-interlingua
DEPENDS+=	tex-babel-sorbian-[0-9]*:../../print/tex-babel-sorbian
DEPENDS+=	tex-babel-thai-[0-9]*:../../print/tex-babel-thai
DEPENDS+=	tex-babel-vietnamese-[0-9]*:../../print/tex-babel-vietnamese
DEPENDS+=	tex-cjhebrew-[0-9]*:../../fonts/tex-cjhebrew
DEPENDS+=	tex-ctib-[0-9]*:../../print/tex-ctib
DEPENDS+=	tex-fonts-tlwg-[0-9]*:../../fonts/tex-fonts-tlwg
DEPENDS+=	tex-hyphen-afrikaans-[0-9]*:../../print/tex-hyphen-afrikaans
DEPENDS+=	tex-hyphen-coptic-[0-9]*:../../print/tex-hyphen-coptic
DEPENDS+=	tex-hyphen-esperanto-[0-9]*:../../print/tex-hyphen-esperanto
DEPENDS+=	tex-hyphen-georgian-[0-9]*:../../print/tex-hyphen-georgian
DEPENDS+=	tex-hyphen-indonesian-[0-9]*:../../print/tex-hyphen-indonesian
DEPENDS+=	tex-hyphen-interlingua-[0-9]*:../../print/tex-hyphen-interlingua
DEPENDS+=	tex-hyphen-thai-[0-9]*:../../print/tex-hyphen-thai
DEPENDS+=	tex-hyphen-turkmen-[0-9]*:../../print/tex-hyphen-turkmen
# lshort-thai is documentation only
# lshort-vietnamese is documentation only
# ntheorem-vn is documentation only
DEPENDS+=	tex-vntex-[0-9]*:../../print/tex-vntex

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
