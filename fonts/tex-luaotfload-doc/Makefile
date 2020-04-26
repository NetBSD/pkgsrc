# $NetBSD: Makefile,v 1.10 2020/04/26 12:21:16 markd Exp $

DISTNAME=	luaotfload.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.12
TEXLIVE_REV=	53652

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luaotfload
COMMENT=	Documentation for tex-luaotfload
LICENSE=	gnu-gpl-v2

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
