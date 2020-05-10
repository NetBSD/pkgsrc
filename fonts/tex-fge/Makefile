# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:44 markd Exp $

DISTNAME=	fge
PKGNAME=	tex-${DISTNAME}-1.25
PKGREVISION=	1
TEXLIVE_REV=	37628

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fge
COMMENT=	Font for Frege's Grundgesetze der Arithmetik
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	fge.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
