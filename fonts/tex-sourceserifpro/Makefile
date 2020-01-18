# $NetBSD: Makefile,v 1.5 2020/01/18 23:31:53 rillig Exp $

DISTNAME=	sourceserifpro
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	49120

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/sourceserifpro
COMMENT=	Use SourceSerifPro with TeX(-alike) systems
LICENSE=	ofl-v1.1 AND lppl-1.3c

TEX_MAP_FILES+=	SourceSerifPro.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
