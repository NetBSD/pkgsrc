# $NetBSD: Makefile,v 1.1.1.1 2012/03/04 01:13:42 minskim Exp $

DISTNAME=	japanese-otf
PKGNAME=	tex-${DISTNAME}-1.7b4
CATEGORIES=	fonts
TEXLIVE_REV=	25453

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Advanced font selection for platex and its friends

TEX_KANJIMAP_FILES+=	otf-cktx.map
TEX_KANJIMAP_FILES+=	otf-@kanjiEmbed@.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
