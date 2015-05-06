# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:44 markd Exp $

DISTNAME=	collection-langkorean
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	33790

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Korean TeX packages

DEPENDS+=	texlive-collection-langcjk-[0-9]*:../../meta-pkgs/texlive-collection-langcjk

# depend cjk-ko
# depend kotex-oblivoir
# depend kotex-plain
# depend kotex-utf
# depend kotex-utils
# depend lshort-korean
DEPENDS+=	tex-nanumtype1-[0-9]*:../../fonts/tex-nanumtype1
DEPENDS+=	tex-uhc-[0-9]*:../../fonts/tex-uhc


META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
