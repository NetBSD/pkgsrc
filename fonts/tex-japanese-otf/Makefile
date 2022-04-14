# $NetBSD: Makefile,v 1.15 2022/04/14 01:37:21 markd Exp $

DISTNAME=	japanese-otf
PKGNAME=	tex-${DISTNAME}-20220305
TEXLIVE_REV=	62455

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/japanese-otf
COMMENT=	Advanced font selection for platex and its friends
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex-fontmaps-[0-9]*:../../fonts/tex-ptex-fontmaps

TEX_KANJIMAP_FILES+=	otf-@jaEmbed@.map
TEX_KANJIMAP_FILES+=	otf-sc-@scEmbed@.map
TEX_KANJIMAP_FILES+=	otf-tc-@tcEmbed@.map
TEX_KANJIMAP_FILES+=	otf-ko-@koEmbed@.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
