# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:13 rillig Exp $

DISTNAME=	baskervald
PKGNAME=	tex-${DISTNAME}-1.016
TEXLIVE_REV=	19490

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/baskervaldadf
COMMENT=	Baskervald ADF fonts collection with TeX/LaTeX support
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	ybv.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
