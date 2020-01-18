# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:28 rillig Exp $

DISTNAME=	esstix
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	22426

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/esstix
COMMENT=	PostScript versions of the ESSTIX, with macro support
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	ESSTIX.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
