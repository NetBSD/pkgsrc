# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:12 rillig Exp $

DISTNAME=	aurical
PKGNAME=	tex-${DISTNAME}-1.5
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/aurical
COMMENT=	Calligraphic fonts for use with LaTeX in T1 encoding
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	aurical.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
