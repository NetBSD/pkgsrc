# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:53 markd Exp $

DISTNAME=	romande
PKGNAME=	tex-${DISTNAME}-1.008.v7.sc
PKGREVISION=	1
TEXLIVE_REV=	19537

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/romandeadf
COMMENT=	Romande ADF fonts and LaTeX support
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	yrd.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
