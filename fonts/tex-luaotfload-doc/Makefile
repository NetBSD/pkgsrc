# $NetBSD: Makefile,v 1.11 2020/05/11 11:02:06 markd Exp $

DISTNAME=	luaotfload.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.14
TEXLIVE_REV=	55064

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luaotfload
COMMENT=	Documentation for tex-luaotfload
LICENSE=	gnu-gpl-v2

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
