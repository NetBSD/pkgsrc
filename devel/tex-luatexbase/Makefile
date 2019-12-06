# $NetBSD: Makefile,v 1.7 2019/12/06 19:18:35 markd Exp $

DISTNAME=	luatexbase
PKGNAME=	tex-${DISTNAME}-1.3
PKGREVISION=	1
TEXLIVE_REV=	38550

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Basic resource management for LuaTeX code
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ctablestack-[0-9]*:../../print/tex-ctablestack
DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
