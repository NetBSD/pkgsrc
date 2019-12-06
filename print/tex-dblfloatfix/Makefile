# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:24 markd Exp $

DISTNAME=	dblfloatfix
PKGNAME=	tex-${DISTNAME}-1.0a
TEXLIVE_REV=	28983

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Fixes for twocolumn floats
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
