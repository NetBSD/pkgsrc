# $NetBSD: Makefile,v 1.2 2019/12/06 19:29:56 markd Exp $

DISTNAME=	esstix
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	22426

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/esstix
COMMENT=	PostScript versions of the ESSTIX, with macro support
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	ESSTIX.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
