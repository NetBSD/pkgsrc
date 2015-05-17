# $NetBSD: Makefile,v 1.5 2015/05/17 11:50:25 markd Exp $

DISTNAME=	collection-langczechslovak
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	32550

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Czech/Slovak TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-babel-czech-[0-9]*:../../print/tex-babel-czech
DEPENDS+=	tex-babel-slovak-[0-9]*:../../print/tex-babel-slovak
# depend cnbwp
DEPENDS+=	tex-cs-[0-9]*:../../fonts/tex-cs
# depend csbulletin
# depend cslatex
# depend csplain
# cstex is documentation only
DEPENDS+=	tex-hyphen-czech-[0-9]*:../../print/tex-hyphen-czech
DEPENDS+=	tex-hyphen-slovak-[0-9]*:../../print/tex-hyphen-slovak
# depend vlna
# lshort-czech is documentation only
# lshort-slovak is documentation only
# texlive-cz is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
