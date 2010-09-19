# $NetBSD: Makefile,v 1.4 2010/09/19 23:58:41 minskim Exp $

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2010
TEXLIVE_REV=	19724

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvips

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
