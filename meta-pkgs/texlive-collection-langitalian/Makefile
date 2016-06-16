# $NetBSD: Makefile,v 1.5 2016/06/16 04:03:15 markd Exp $

DISTNAME=	collection-langitalian
PKGNAME=	texlive-${DISTNAME}-2016pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	30372

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Italian TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# amsldoc-it is documentation only
# amsmath-it is documentation only
# amsthdoc-it is documentation only
DEPENDS+=	tex-babel-italian-[0-9]*:../../print/tex-babel-italian
# depend codicefiscaleitaliano
# fancyhdr-it is documentation only
# depend fixltxhyph
# depend frontespizio
DEPENDS+=	tex-hyphen-italian-[0-9]*:../../print/tex-hyphen-italian
# depend itnumpar
# l2tabu-italian is documentation only
# latex4wp-it is documentation only
# depend layaureo
# lshort-italian is documentation only
# psfrag-italian is documentation only
# texlive-it is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
