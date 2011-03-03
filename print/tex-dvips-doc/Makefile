# $NetBSD: Makefile,v 1.9 2011/03/03 03:16:39 minskim Exp $

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2010
TEXLIVE_REV=	21308

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvips

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
