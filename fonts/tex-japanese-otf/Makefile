# $NetBSD: Makefile,v 1.14 2022/04/14 01:33:34 markd Exp $

DISTNAME=	japanese-otf
PKGNAME=	tex-${DISTNAME}-1.7b8.62455
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
