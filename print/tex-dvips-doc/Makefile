# $NetBSD: Makefile,v 1.21 2020/01/18 23:34:02 rillig Exp $

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2017
TEXLIVE_REV=	44167

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dvips
COMMENT=	Documentation for tex-dvips
LICENSE=	gnu-gpl-v2

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/info texmf-dist/doc/man

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
