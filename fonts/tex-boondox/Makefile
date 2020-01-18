# $NetBSD: Makefile,v 1.4 2020/01/18 23:31:15 rillig Exp $

DISTNAME=	boondox
PKGNAME=	tex-${DISTNAME}-1.02d
TEXLIVE_REV=	43344

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/boondox
COMMENT=	Mathematical alphabets derived from the STIX fonts
LICENSE=	lppl-1.3c AND ofl-v1.1

TEX_MAP_FILES+=	boondox.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
