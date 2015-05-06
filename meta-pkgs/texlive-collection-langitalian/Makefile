# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:44 markd Exp $

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
# depend lshort-italian
# depend psfrag-italian
# depend texlive-it

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
