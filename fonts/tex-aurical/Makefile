# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:38 markd Exp $

DISTNAME=	aurical
PKGNAME=	tex-${DISTNAME}-1.5
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/aurical
COMMENT=	Calligraphic fonts for use with LaTeX in T1 encoding
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	aurical.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
