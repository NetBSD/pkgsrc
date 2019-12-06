# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:09 markd Exp $

DISTNAME=	ptex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.2pl36135
TEXLIVE_REV=	36135

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ptex

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/man

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
