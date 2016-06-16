# $NetBSD: Makefile,v 1.1 2016/06/16 03:57:30 markd Exp $

DISTNAME=	ptex-fonts
PKGNAME=	tex-${DISTNAME}-0.0.2016
TEXLIVE_REV=	41207

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/ptex-fonts
COMMENT=	Fonts for use with pTeX
LICENSE=	modified-bsd

#TEX_KANJIMAP_FILES+=	morisawa.map
TEX_KANJIMAP_FILES+=	ptex-@kanjiEmbed@@kanjiVariant@.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
