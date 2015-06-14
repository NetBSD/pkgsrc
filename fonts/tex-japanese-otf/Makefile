# $NetBSD: Makefile,v 1.3 2015/06/14 11:19:59 markd Exp $

DISTNAME=	japanese-otf
PKGNAME=	tex-${DISTNAME}-1.7b6.36953
CATEGORIES=	fonts
TEXLIVE_REV=	36953

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Advanced font selection for platex and its friends

TEX_KANJIMAP_FILES+=	otf-cktx.map
TEX_KANJIMAP_FILES+=	otf-@kanjiEmbed@.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
