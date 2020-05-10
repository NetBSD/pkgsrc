# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:40 markd Exp $

DISTNAME=	cantarell
PKGNAME=	tex-${DISTNAME}-3.2
PKGREVISION=	1
TEXLIVE_REV=	51459

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cantarell
COMMENT=	LaTeX support for the Cantarell font family
LICENSE=	ofl-v1.1 AND lppl-1.3c

TEX_MAP_FILES+=	cantarell.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
