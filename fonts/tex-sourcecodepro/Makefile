# $NetBSD: Makefile,v 1.5 2019/12/06 19:32:25 markd Exp $

DISTNAME=	sourcecodepro
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	51163

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/sourcecodepro
COMMENT=	Use SourceCodePro with TeX(-alike) systems
LICENSE=	ofl-v1.1 AND lppl-1.3c

TEX_MAP_FILES+=	SourceCodePro.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
