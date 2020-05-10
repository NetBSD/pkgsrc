# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:38 markd Exp $

DISTNAME=	auncial-new
PKGNAME=	tex-${DISTNAME}-2.0
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/auncial-new
COMMENT=	Artificial Uncial font and LaTeX support macros
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	auncial.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
