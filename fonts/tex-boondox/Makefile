# $NetBSD: Makefile,v 1.3 2019/12/06 19:29:39 markd Exp $

DISTNAME=	boondox
PKGNAME=	tex-${DISTNAME}-1.02d
TEXLIVE_REV=	43344

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/boondox
COMMENT=	Mathematical alphabets derived from the STIX fonts
LICENSE=	lppl-1.3c AND ofl-v1.1

TEX_MAP_FILES+=	boondox.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
