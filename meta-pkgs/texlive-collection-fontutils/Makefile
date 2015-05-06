# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:42 markd Exp $

DISTNAME=	collection-fontutils
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	36028

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Graphics and font utilities for TeX

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend accfonts
# depend afm2pl
# depend dosepsbin
DEPENDS+=	tex-epstopdf-[0-9]*:../../graphics/tex-epstopdf
# depend fontware
# depend lcdftypetools
DEPENDS+=	ps2pkm-[0-9]*:../../fonts/ps2pkm
DEPENDS+=	tex-pstools-[0-9]*:../../graphics/tex-pstools
# depend psutils
# depend dvipsconfig
DEPENDS+=	tex-fontinst-[0-9]*:../../fonts/tex-fontinst
# depend fontools
# depend mf2pt1
# depend t1utils
DEPENDS+=	tex-ttfutils-[0-9]*:../../fonts/tex-ttfutils

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
