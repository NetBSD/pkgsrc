# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:43 rillig Exp $

DISTNAME=	mnsymbol
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	18651

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mnsymbol
COMMENT=	Mathematical symbol font for Adobe MinionPro
LICENSE=	public-domain

TEX_MAP_FILES+=	MnSymbol.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
