# $NetBSD: Makefile,v 1.13 2021/06/06 11:09:50 markd Exp $

DISTNAME=	luaotfload.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.18
TEXLIVE_REV=	59293

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luaotfload
COMMENT=	Documentation for tex-luaotfload
LICENSE=	gnu-gpl-v2

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
