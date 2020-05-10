# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:39 markd Exp $

DISTNAME=	boondox
PKGNAME=	tex-${DISTNAME}-1.02d
PKGREVISION=	1
TEXLIVE_REV=	43344

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/boondox
COMMENT=	Mathematical alphabets derived from the STIX fonts
LICENSE=	lppl-1.3c AND ofl-v1.1

TEX_MAP_FILES+=	boondox.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
