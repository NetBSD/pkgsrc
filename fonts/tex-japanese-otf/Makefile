# $NetBSD: Makefile,v 1.6 2017/07/27 11:11:57 markd Exp $

DISTNAME=	japanese-otf
PKGNAME=	tex-${DISTNAME}-1.7b6.42950
PKGREVISION=	1
TEXLIVE_REV=	42950

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/japanese-otf
COMMENT=	Advanced font selection for platex and its friends
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex-fontmaps-[0-9]*:../../fonts/tex-ptex-fontmaps

TEX_KANJIMAP_FILES+=	otf-@jaEmbed@.map
TEX_KANJIMAP_FILES+=	otf-sc-@scEmbed@.map
TEX_KANJIMAP_FILES+=	otf-tc-@tcEmbed@.map
TEX_KANJIMAP_FILES+=	otf-ko-@koEmbed@.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
