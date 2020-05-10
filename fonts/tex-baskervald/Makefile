# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:38 markd Exp $

DISTNAME=	baskervald
PKGNAME=	tex-${DISTNAME}-1.016
PKGREVISION=	1
TEXLIVE_REV=	19490

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/baskervaldadf
COMMENT=	Baskervald ADF fonts collection with TeX/LaTeX support
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	ybv.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
