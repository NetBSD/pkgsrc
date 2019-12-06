# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:41 markd Exp $

DISTNAME=	version
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	21920

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Conditionally include text

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
