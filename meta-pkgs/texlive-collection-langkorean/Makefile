# $NetBSD: Makefile,v 1.8 2017/07/27 11:18:49 markd Exp $

DISTNAME=	collection-langkorean
PKGNAME=	texlive-${DISTNAME}-2017pre2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	42106

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Korean TeX packages

DEPENDS+=	texlive-collection-langcjk-[0-9]*:../../meta-pkgs/texlive-collection-langcjk

DEPENDS+=	tex-baekmuk-[0-9]*:../../fonts/tex-baekmuk
DEPENDS+=	tex-cjk-ko-[0-9]*:../../print/tex-cjk-ko
DEPENDS+=	tex-kotex-oblivoir-[0-9]*:../../print/tex-kotex-oblivoir
DEPENDS+=	tex-kotex-plain-[0-9]*:../../print/tex-kotex-plain
DEPENDS+=	tex-kotex-utf-[0-9]*:../../print/tex-kotex-utf
DEPENDS+=	tex-kotex-utils-[0-9]*:../../print/tex-kotex-utils
# lshort-korean is documentation only
DEPENDS+=	tex-nanumtype1-[0-9]*:../../fonts/tex-nanumtype1
DEPENDS+=	tex-uhc-[0-9]*:../../fonts/tex-uhc
# depend unfonts-core
# depend unfonts-extra

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
