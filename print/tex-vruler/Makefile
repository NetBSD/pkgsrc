# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:42 markd Exp $

DISTNAME=	vruler
PKGNAME=	tex-${DISTNAME}-2.3
PKGREVISION=	1
TEXLIVE_REV=	21598

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Numbering text
LICENSE=	lppl-1.0

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
