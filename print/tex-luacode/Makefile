# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:26 rillig Exp $

DISTNAME=	luacode
PKGNAME=	tex-${DISTNAME}-1.2a
TEXLIVE_REV=	25193

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luacode
COMMENT=	Helper for executing lua code from within TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
