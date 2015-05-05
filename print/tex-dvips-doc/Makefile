# $NetBSD: Makefile,v 1.15 2015/05/05 16:59:23 wiz Exp $

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	36020

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dvips
COMMENT=	Documentation for tex-dvips
LICENSE=	gnu-gpl-v2

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/info texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
