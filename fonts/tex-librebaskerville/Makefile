# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:48 markd Exp $

DISTNAME=	librebaskerville
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	31741

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/librebaskerville
COMMENT=	LaTeX support for the Libre Baskerville family of fonts
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	LibreBaskerville.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
