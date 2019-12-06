# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:35 markd Exp $

DISTNAME=	truncate
PKGNAME=	tex-${DISTNAME}-3.6
TEXLIVE_REV=	18921

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Truncate text to a specified width
LICENSE=	public-domain

CONFLICTS+=	tex-ltxmisc<2010

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
