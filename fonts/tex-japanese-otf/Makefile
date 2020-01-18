# $NetBSD: Makefile,v 1.10 2020/01/18 23:31:39 rillig Exp $

DISTNAME=	japanese-otf
PKGNAME=	tex-${DISTNAME}-1.7b8
TEXLIVE_REV=	50769

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/japanese-otf
COMMENT=	Advanced font selection for platex and its friends
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex-fontmaps-[0-9]*:../../fonts/tex-ptex-fontmaps

TEX_KANJIMAP_FILES+=	otf-@jaEmbed@.map
TEX_KANJIMAP_FILES+=	otf-sc-@scEmbed@.map
TEX_KANJIMAP_FILES+=	otf-tc-@tcEmbed@.map
TEX_KANJIMAP_FILES+=	otf-ko-@koEmbed@.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
