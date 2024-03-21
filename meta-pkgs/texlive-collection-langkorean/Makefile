# $NetBSD: Makefile,v 1.15 2024/03/21 20:00:54 markd Exp $

DISTNAME=	collection-langkorean
PKGNAME=	texlive-${DISTNAME}-2024
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	54074

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
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
DEPENDS+=	tex-pmhanguljamo-[0-9]*:../../print/tex-pmhanguljamo
DEPENDS+=	tex-uhc-[0-9]*:../../fonts/tex-uhc
DEPENDS+=	tex-unfonts-core-[0-9]*:../../fonts/tex-unfonts-core
DEPENDS+=	tex-unfonts-extra-[0-9]*:../../fonts/tex-unfonts-extra

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
