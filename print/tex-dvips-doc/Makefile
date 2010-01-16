# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 05:50:43 minskim Exp $
# TeX Live Revision 16376

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009.16376

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvips

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
