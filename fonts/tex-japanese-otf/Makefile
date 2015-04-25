# $NetBSD: Makefile,v 1.2 2015/04/25 08:01:05 markd Exp $

DISTNAME=	japanese-otf
PKGNAME=	tex-${DISTNAME}-1.7b6
CATEGORIES=	fonts
TEXLIVE_REV=	32233

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Advanced font selection for platex and its friends

TEX_KANJIMAP_FILES+=	otf-cktx.map
TEX_KANJIMAP_FILES+=	otf-@kanjiEmbed@.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
