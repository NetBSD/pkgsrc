# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:44 markd Exp $

DISTNAME=	ethiop-t1
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ethiop-t1
COMMENT=	Type 1 versions of Amharic fonts
LICENSE=	gnu-gpl-v2

TEX_MIXEDMAP_FILES+=	ethiop.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
