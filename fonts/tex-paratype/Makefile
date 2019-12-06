# $NetBSD: Makefile,v 1.2 2019/12/06 19:32:19 markd Exp $

DISTNAME=	paratype
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	32859

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/paratype
COMMENT=	LaTeX support for free fonts by ParaType
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	paratype-type1.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
