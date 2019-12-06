# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:31 markd Exp $

DISTNAME=	titleref
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	18729

MAINTAINER=	minskim@NetBSD.org
COMMENT=	\\titleref command to cross-reference section titles
LICENSE=	public-domain

CONFLICTS+=	tex-ltxmisc<2010

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
