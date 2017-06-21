# $NetBSD: Makefile,v 1.2 2017/06/21 11:46:00 markd Exp $

DISTNAME=	ptex-fonts
PKGNAME=	tex-${DISTNAME}-2017
TEXLIVE_REV=	42950

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/ptex-fonts
COMMENT=	Fonts for use with pTeX
LICENSE=	modified-bsd

#TEX_KANJIMAP_FILES+=	morisawa.map
TEX_KANJIMAP_FILES+=	ptex-@jaEmbed@@jaVariant@.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
