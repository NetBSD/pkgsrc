# $NetBSD: Makefile,v 1.1 2021/02/21 08:36:53 markd Exp $

DISTNAME=	japanese-otf-uptex
PKGNAME=	tex-${DISTNAME}-0.26
TEXLIVE_REV=	56932

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/japanese-otf-uptex
COMMENT=	Support for Japanese OTF files in upLaTeX
LICENSE=	modified-bsd

DEPENDS+=	tex-japanese-otf-[0-9]*:../../fonts/tex-japanese-otf

TEX_KANJIMAP_FILES+=	otf-up-@jaEmbed@.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
