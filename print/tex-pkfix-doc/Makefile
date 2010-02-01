# $NetBSD: Makefile,v 1.2 2010/02/01 00:57:07 minskim Exp $
# TeX Live Revision 15878

DISTNAME=	pkfix.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.5

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pkfix

CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
