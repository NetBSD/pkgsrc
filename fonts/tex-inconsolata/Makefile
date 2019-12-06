# $NetBSD: Makefile,v 1.7 2019/12/06 19:30:07 markd Exp $

DISTNAME=	inconsolata
PKGNAME=	tex-${DISTNAME}-1.121
TEXLIVE_REV=	51433

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/inconsolata
COMMENT=	Monospaced font, with support files for use with TeX
LICENSE=	ofl-v1.1 AND apache-2.0 AND lppl-1.3c

TEX_MAP_FILES+=	zi4.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
