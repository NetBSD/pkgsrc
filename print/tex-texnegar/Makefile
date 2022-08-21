# $NetBSD: Makefile,v 1.1 2022/08/21 15:16:58 wiz Exp $

DISTNAME=	texnegar
PKGNAME=	tex-${DISTNAME}-0.1e
TEXLIVE_REV=	57692

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dma8hm1334.bitbucket.io/
COMMENT=	Kashida justification in XeLaTeX and LuaLaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-environ-[0-9]*:../../print/tex-environ
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
# graphicx
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
# l3keys2e, xparse
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-newverbs-[0-9]*:../../print/tex-newverbs
# array
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
# zref-savepos
DEPENDS+=	tex-zref-[0-9]*:../../print/tex-zref

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
