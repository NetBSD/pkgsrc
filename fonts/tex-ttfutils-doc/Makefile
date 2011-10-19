# $NetBSD: Makefile,v 1.1.1.1 2011/10/19 20:11:55 minskim Exp $

DISTNAME=	ttfutils.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2011
TEXLIVE_REV=	23089

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ttfutils

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/man

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
