# $NetBSD: Makefile,v 1.3 2019/12/06 20:21:57 markd Exp $

DISTNAME=	magaz
PKGNAME=	tex-${DISTNAME}-0.4
TEXLIVE_REV=	24694

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Magazine layout

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
