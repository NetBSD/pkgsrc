# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:36 rillig Exp $

DISTNAME=	hacm
PKGNAME=	tex-${DISTNAME}-0.1
TEXLIVE_REV=	27671

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hacm
COMMENT=	Font support for the Arka language
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	hacm.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
