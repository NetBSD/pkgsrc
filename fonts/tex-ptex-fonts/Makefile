# $NetBSD: Makefile,v 1.4 2017/10/21 02:54:47 markd Exp $

DISTNAME=	ptex-fonts
PKGNAME=	tex-${DISTNAME}-2017.45138
TEXLIVE_REV=	45138

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/ptex-fonts
COMMENT=	Fonts for use with pTeX
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex-fontmaps-[0-9]*:../../fonts/tex-ptex-fontmaps

#TEX_KANJIMAP_FILES+=	morisawa.map
TEX_KANJIMAP_FILES+=	ptex-@jaEmbed@@jaVariant@.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
