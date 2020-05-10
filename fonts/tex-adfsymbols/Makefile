# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:36 markd Exp $

DISTNAME=	adfsymbols
PKGNAME=	tex-${DISTNAME}-1.2b
PKGREVISION=	1
TEXLIVE_REV=	54512

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/adfsymbols
COMMENT=	SymbolsADF with TeX/LaTeX support
LICENSE=	gnu-gpl-v2 AND lppl-1.3c

TEX_MAP_FILES+=	ArrowsADF.map
TEX_MAP_FILES+=	BulletsADF.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
