# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:23 rillig Exp $

DISTNAME=	dejavu
PKGNAME=	tex-${DISTNAME}-2.34
TEXLIVE_REV=	31771

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dejavu
COMMENT=	LaTeX support for the DejaVu fonts
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	dejavu-type1.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
