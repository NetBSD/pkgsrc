# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:42 markd Exp $

DISTNAME=	dejavu
PKGNAME=	tex-${DISTNAME}-2.34
PKGREVISION=	1
TEXLIVE_REV=	31771

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dejavu
COMMENT=	LaTeX support for the DejaVu fonts
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	dejavu-type1.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
