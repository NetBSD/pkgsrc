# $NetBSD: Makefile,v 1.4 2015/04/25 04:13:37 markd Exp $

DISTNAME=	pkfix.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.7
TEXLIVE_REV=	26032

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pkfix
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
