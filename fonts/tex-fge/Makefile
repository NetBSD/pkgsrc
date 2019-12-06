# $NetBSD: Makefile,v 1.3 2019/12/06 19:29:58 markd Exp $

DISTNAME=	fge
PKGNAME=	tex-${DISTNAME}-1.25
TEXLIVE_REV=	37628

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fge
COMMENT=	Font for Frege's Grundgesetze der Arithmetik
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	fge.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
