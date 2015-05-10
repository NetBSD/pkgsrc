# $NetBSD: Makefile,v 1.3 2015/05/10 04:36:16 markd Exp $

DISTNAME=	collection-langitalian
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	30372

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Italian TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend amsldoc-it
# depend amsmath-it
# depend amsthdoc-it
DEPENDS+=	tex-babel-italian-[0-9]*:../../print/tex-babel-italian
# depend codicefiscaleitaliano
# depend fancyhdr-it
# depend fixltxhyph
# depend frontespizio
DEPENDS+=	tex-hyphen-italian-[0-9]*:../../print/tex-hyphen-italian
# depend itnumpar
# depend l2tabu-italian
# depend latex4wp-it
# depend layaureo
# lshort-italian is documentation only
# depend psfrag-italian
# texlive-it is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
