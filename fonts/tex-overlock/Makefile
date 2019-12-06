# $NetBSD: Makefile,v 1.3 2019/12/06 19:32:18 markd Exp $

DISTNAME=	overlock
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	51294

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/overlock
COMMENT=	Overlook sans fonts with LaTeX support
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	overlock.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
