# $NetBSD: Makefile,v 1.14 2015/04/25 03:49:23 markd Exp $

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	36020

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvips
LICENSE=	gnu-gpl-v2

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/info texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
