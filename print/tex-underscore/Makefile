# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:38 markd Exp $

DISTNAME=	underscore
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	18261

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Control the behaviour of "_" in text
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-ltxmisc<2010

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
