# $NetBSD: Makefile,v 1.14 2022/04/17 11:17:44 markd Exp $

DISTNAME=	collection-langczechslovak
PKGNAME=	texlive-${DISTNAME}-2022
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	54074

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Czech/Slovak TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-babel-czech-[0-9]*:../../print/tex-babel-czech
DEPENDS+=	tex-babel-slovak-[0-9]*:../../print/tex-babel-slovak
DEPENDS+=	tex-cnbwp-[0-9]*:../../print/tex-cnbwp
DEPENDS+=	tex-cs-[0-9]*:../../fonts/tex-cs
DEPENDS+=	tex-csbulletin-[0-9]*:../../print/tex-csbulletin
DEPENDS+=	tex-cslatex-[0-9]*:../../print/tex-cslatex
DEPENDS+=	tex-csplain-[0-9]*:../../print/tex-csplain
# cstex is documentation only
DEPENDS+=	tex-hyphen-czech-[0-9]*:../../print/tex-hyphen-czech
DEPENDS+=	tex-hyphen-slovak-[0-9]*:../../print/tex-hyphen-slovak
DEPENDS+=	vlna-[0-9]*:../../print/vlna
# lshort-czech is documentation only
# lshort-slovak is documentation only
# texlive-cz is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
