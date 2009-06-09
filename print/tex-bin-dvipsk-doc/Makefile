# $NetBSD: Makefile,v 1.2 2009/06/09 22:49:51 minskim Exp $
# TeX Live Revision 12898

DISTNAME=	bin-dvipsk.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2008.12898

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-bin-dvipsk

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info texmf/doc/man

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
