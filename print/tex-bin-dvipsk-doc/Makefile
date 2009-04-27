# $NetBSD: Makefile,v 1.1.1.1 2009/04/27 15:29:03 minskim Exp $
# TeX Live Revision 12785

DISTNAME=	bin-dvipsk.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2008.12785

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-bin-dvipsk

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info texmf/doc/man

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
