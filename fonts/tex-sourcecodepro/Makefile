# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:53 markd Exp $

DISTNAME=	sourcecodepro
PKGNAME=	tex-${DISTNAME}-2.7
PKGREVISION=	1
TEXLIVE_REV=	51163

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/sourcecodepro
COMMENT=	Use SourceCodePro with TeX(-alike) systems
LICENSE=	ofl-v1.1 AND lppl-1.3c

TEX_MAP_FILES+=	SourceCodePro.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
