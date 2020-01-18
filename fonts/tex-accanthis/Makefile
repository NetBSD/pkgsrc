# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:07 rillig Exp $

DISTNAME=	accanthis
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	32089

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/accanthis
COMMENT=	Accanthis fonts, with LaTeX support
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	accanthis.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
