# $NetBSD: Makefile,v 1.3 2015/08/02 03:01:10 markd Exp $

DISTNAME=	collection-langarabic
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	37746

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Arabic TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend amiri
DEPENDS+=	tex-arabi-[0-9]*:../../print/tex-arabi
# depend arabi-add
DEPENDS+=	tex-arabtex-[0-9]*:../../print/tex-arabtex
# depend bidi
# depend bidihl
# depend dad
# depend ghab
DEPENDS+=	tex-hyphen-arabic-[0-9]*:../../print/tex-hyphen-arabic
DEPENDS+=	tex-hyphen-farsi-[0-9]*:../../print/tex-hyphen-farsi
# depend imsproc
# lshort-persian is documentation only
# depend persian-bib
# depend simurgh
# depend tram

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
