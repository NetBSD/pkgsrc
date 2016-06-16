# $NetBSD: Makefile,v 1.3 2016/06/16 04:03:14 markd Exp $

DISTNAME=	collection-langindic
PKGNAME=	texlive-${DISTNAME}-2016pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	35737

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Indic scripts TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend bangtex
# depend bengali
# depend burmese
# depend devnag
# depend ebong
DEPENDS+=	tex-hyphen-indic-[0-9]*:../../print/tex-hyphen-indic
DEPENDS+=	tex-hyphen-sanskrit-[0-9]*:../../print/tex-hyphen-sanskrit
# depend sanskrit
# depend sanskrit-t1
# depend velthuis
# depend wnri
# depend wnri-latex
# depend xetex-devanagari

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
