# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:51 rillig Exp $

DISTNAME=	romande
PKGNAME=	tex-${DISTNAME}-1.008.v7.sc
TEXLIVE_REV=	19537

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/romandeadf
COMMENT=	Romande ADF fonts and LaTeX support
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	yrd.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
