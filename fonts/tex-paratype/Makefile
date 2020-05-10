# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:51 markd Exp $

DISTNAME=	paratype
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	32859

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/paratype
COMMENT=	LaTeX support for free fonts by ParaType
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	paratype-type1.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
