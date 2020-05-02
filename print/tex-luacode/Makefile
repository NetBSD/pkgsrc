# $NetBSD: Makefile,v 1.5 2020/05/02 02:42:48 markd Exp $

DISTNAME=	luacode
PKGNAME=	tex-${DISTNAME}-1.2a
PKGREVISION=	1
TEXLIVE_REV=	25193

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luacode
COMMENT=	Helper for executing lua code from within TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
