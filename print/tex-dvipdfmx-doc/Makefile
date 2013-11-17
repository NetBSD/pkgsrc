# $NetBSD: Makefile,v 1.6 2013/11/17 17:27:35 minskim Exp $

DISTNAME=	dvipdfmx.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2013
TEXLIVE_REV=	31830

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvipdfmx

TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
