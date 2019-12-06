# $NetBSD: Makefile,v 1.5 2019/12/06 20:22:52 markd Exp $

DISTNAME=	needspace
PKGNAME=	tex-${DISTNAME}-1.3d
TEXLIVE_REV=	29601

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Insert pagebreak if not enough space
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
