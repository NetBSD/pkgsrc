# $NetBSD: Makefile,v 1.10 2022/04/10 03:37:13 markd Exp $

DISTNAME=	collection-langgreek
PKGNAME=	texlive-${DISTNAME}-2020pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	61820

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Greek TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-babel-greek-[0-9]*:../../print/tex-babel-greek
# depend begingreek
# depend betababel
DEPENDS+=	tex-cbfonts-[0-9]*:../../fonts/tex-cbfonts
DEPENDS+=	tex-cbfonts-fd-[0-9]*:../../fonts/tex-cbfonts-fd
# depend gfsbaskerville
# depend gfsporson
# depend greek-fontenc
DEPENDS+=	tex-greek-inputenc-[0-9]*:../../print/tex-greek-inputenc
# depend greekdates
# depend greektex
# depend greektonoi
DEPENDS+=	tex-hyphen-ancientgreek-[0-9]*:../../print/tex-hyphen-ancientgreek
DEPENDS+=	tex-hyphen-greek-[0-9]*:../../print/tex-hyphen-greek
# depend ibycus-babel
# depend ibygrk
# depend kerkis
# depend levy
# depend lgreek
# depend mkgrkindex
# depend talos
# depend teubner
# depend xgreek
# depend yannisgr

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
