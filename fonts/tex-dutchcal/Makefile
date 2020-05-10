# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:43 markd Exp $

DISTNAME=	dutchcal
PKGNAME=	tex-${DISTNAME}-1.0
PKGREVISION=	1
TEXLIVE_REV=	23448

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dutchcal
COMMENT=	Reworking of ESSTIX13, adding a bold version
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	dutchcal.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
