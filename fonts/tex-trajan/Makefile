# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:55 markd Exp $

DISTNAME=	trajan
PKGNAME=	tex-${DISTNAME}-1.1
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/trajan
COMMENT=	Fonts from the Trajan column in Rome
LICENSE=	lppl-1.3c

TEX_MIXEDMAP_FILES+=	trajan.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
