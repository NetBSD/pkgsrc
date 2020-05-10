# $NetBSD: Makefile,v 1.12 2020/05/10 11:32:14 tnn Exp $

DISTNAME=	collection-fontutils
PKGNAME=	texlive-${DISTNAME}-2020
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	54074

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Graphics and font utilities for TeX

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-accfonts-[0-9]*:../../fonts/tex-accfonts
DEPENDS+=	tex-afm2pl-[0-9]*:../../fonts/tex-afm2pl
DEPENDS+=	tex-dosepsbin-[0-9]*:../../fonts/tex-dosepsbin
DEPENDS+=	tex-epstopdf-[0-9]*:../../graphics/tex-epstopdf
# fontware is entirely included in web2c
DEPENDS+=	lcdftypetools-[0-9]*:../../fonts/lcdftypetools
# metatype1 is empty
DEPENDS+=	ps2pkm-[0-9]*:../../fonts/ps2pkm
DEPENDS+=	ps2eps-[0-9]*:../../graphics/ps2eps
DEPENDS+=	psutils-[0-9]*:../../print/psutils
DEPENDS+=	tex-dvipsconfig-[0-9]*:../../fonts/tex-dvipsconfig
DEPENDS+=	tex-fontinst-[0-9]*:../../fonts/tex-fontinst
DEPENDS+=	tex-fontools-[0-9]*:../../fonts/tex-fontools
DEPENDS+=	tex-mf2pt1-[0-9]*:../../fonts/tex-mf2pt1
DEPENDS+=	t1utils-[0-9]*:../../fonts/t1utils
DEPENDS+=	tex-ttfutils-[0-9]*:../../fonts/tex-ttfutils

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
