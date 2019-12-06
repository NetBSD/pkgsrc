# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:11 markd Exp $

DISTNAME=	relsize
PKGNAME=	tex-${DISTNAME}-4.1
TEXLIVE_REV=	30707

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Set the font size relative to the current font size
LICENSE=	public-domain

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
