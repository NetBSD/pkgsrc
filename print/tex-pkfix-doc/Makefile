# $NetBSD: Makefile,v 1.3 2010/10/26 23:53:43 minskim Exp $

DISTNAME=	pkfix.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.5
TEXLIVE_REV=	18835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pkfix

CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
