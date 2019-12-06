# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:14 markd Exp $

DISTNAME=	selectp
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	20185

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Select pages to be output
LICENSE=	public-domain

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
