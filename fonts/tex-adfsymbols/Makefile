# $NetBSD: Makefile,v 1.4 2020/04/26 12:21:11 markd Exp $

DISTNAME=	adfsymbols
PKGNAME=	tex-${DISTNAME}-1.2b
TEXLIVE_REV=	54512

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/adfsymbols
COMMENT=	SymbolsADF with TeX/LaTeX support
LICENSE=	gnu-gpl-v2 AND lppl-1.3c

TEX_MAP_FILES+=	ArrowsADF.map
TEX_MAP_FILES+=	BulletsADF.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
