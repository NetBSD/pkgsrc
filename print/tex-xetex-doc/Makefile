# $NetBSD: Makefile,v 1.3 2016/06/16 04:06:18 markd Exp $

DISTNAME=	xetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2016
TEXLIVE_REV=	40963

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-xetex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
