# $NetBSD: Makefile,v 1.4 2016/08/07 07:17:37 markd Exp $

DISTNAME=	japanese-otf
PKGNAME=	tex-${DISTNAME}-1.7b6.41546
TEXLIVE_REV=	41546

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/japanese-otf
COMMENT=	Advanced font selection for platex and its friends
LICENSE=	modified-bsd

TEX_KANJIMAP_FILES+=	otf-cktx.map
TEX_KANJIMAP_FILES+=	otf-@kanjiEmbed@.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
