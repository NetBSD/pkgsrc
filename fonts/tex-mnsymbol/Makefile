# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:49 markd Exp $

DISTNAME=	mnsymbol
PKGNAME=	tex-${DISTNAME}-1.4
PKGREVISION=	1
TEXLIVE_REV=	18651

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mnsymbol
COMMENT=	Mathematical symbol font for Adobe MinionPro
LICENSE=	public-domain

TEX_MAP_FILES+=	MnSymbol.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
