# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:36 markd Exp $

DISTNAME=	twoinone
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	17024

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX style to print two pages on a single page
LICENSE=	public-domain

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
