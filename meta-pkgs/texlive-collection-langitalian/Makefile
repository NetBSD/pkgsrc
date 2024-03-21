# $NetBSD: Makefile,v 1.12 2024/03/21 20:00:54 markd Exp $

DISTNAME=	collection-langitalian
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	55129

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Italian TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# amsldoc-it is documentation only
# amsmath-it is documentation only
# amsthdoc-it is documentation only
# depend antanilipsum
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
# depend verifica

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
