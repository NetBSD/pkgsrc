# $NetBSD: Makefile,v 1.2 2019/12/06 19:29:30 markd Exp $

DISTNAME=	adfsymbols
PKGNAME=	tex-${DISTNAME}-1.001
TEXLIVE_REV=	19766

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/adfsymbols
COMMENT=	SymbolsADF with TeX/LaTeX support
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	ArrowsADF.map
TEX_MAP_FILES+=	BulletsADF.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
