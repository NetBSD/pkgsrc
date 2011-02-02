# $NetBSD: Makefile,v 1.8 2011/02/02 18:27:51 minskim Exp $

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2010
TEXLIVE_REV=	21248

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvips

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
