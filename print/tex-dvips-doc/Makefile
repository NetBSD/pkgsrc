# $NetBSD: Makefile,v 1.2 2010/02/15 20:16:08 minskim Exp $
# TeX Live Revision 16770

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009.16770

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvips

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
