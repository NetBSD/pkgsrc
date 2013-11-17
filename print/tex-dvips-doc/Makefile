# $NetBSD: Makefile,v 1.13 2013/11/17 16:53:18 minskim Exp $

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2013
TEXLIVE_REV=	32132

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvips
LICENSE=	gnu-gpl-v2

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/info texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
