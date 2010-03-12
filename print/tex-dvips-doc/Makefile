# $NetBSD: Makefile,v 1.3 2010/03/12 19:38:22 minskim Exp $
# TeX Live Revision 17180

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009.17180

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvips

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
