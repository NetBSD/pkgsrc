# $NetBSD: Makefile,v 1.2 2019/12/06 19:29:49 markd Exp $

DISTNAME=	dejavu
PKGNAME=	tex-${DISTNAME}-2.34
TEXLIVE_REV=	31771

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dejavu
COMMENT=	LaTeX support for the DejaVu fonts
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	dejavu-type1.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
