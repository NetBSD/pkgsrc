# $NetBSD: Makefile,v 1.3 2019/12/06 19:29:43 markd Exp $

DISTNAME=	cinzel
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	51101

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cinzel
COMMENT=	LaTeX support for Cinzel and Cinzel Decorative fonts
LICENSE=	ofl-v1.1 AND lppl-1.3c

TEX_MAP_FILES+=	cinzel.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
