# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:36 markd Exp $

DISTNAME=	accanthis
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	32089

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/accanthis
COMMENT=	Accanthis fonts, with LaTeX support
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	accanthis.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
