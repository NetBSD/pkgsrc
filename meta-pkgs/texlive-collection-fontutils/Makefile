# $NetBSD: Makefile,v 1.2 2015/05/10 02:23:58 markd Exp $

DISTNAME=	collection-fontutils
PKGNAME=	texlive-${DISTNAME}-2014pre2
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
# fontware is entirely included in web2c
# depend lcdftypetools
DEPENDS+=	ps2pkm-[0-9]*:../../fonts/ps2pkm
DEPENDS+=	tex-pstools-[0-9]*:../../graphics/tex-pstools
DEPENDS+=	psutils-[0-9]*:../../print/psutils
# depend dvipsconfig
DEPENDS+=	tex-fontinst-[0-9]*:../../fonts/tex-fontinst
# depend fontools
# depend mf2pt1
DEPENDS+=	t1utils-[0-9]*:../../fonts/t1utils
DEPENDS+=	tex-ttfutils-[0-9]*:../../fonts/tex-ttfutils

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
