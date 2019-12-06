# $NetBSD: Makefile,v 1.2 2019/12/06 19:30:04 markd Exp $

DISTNAME=	gillius
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	32068

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/gillius
COMMENT=	Gillius fonts with LaTeX support
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	gillius.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
