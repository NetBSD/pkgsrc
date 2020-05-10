# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:55 markd Exp $

DISTNAME=	universalis
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	33860

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/universalis
COMMENT=	Universalis font, with support
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	universalis.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
