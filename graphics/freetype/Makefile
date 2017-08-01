# $NetBSD: Makefile,v 1.31 2017/08/01 14:59:00 wiz Exp $

DISTNAME=		freetype-${FT_VERS}
FT_VERS=		1.5
CATEGORIES=		graphics meta-pkgs textproc

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.freetype.org/
COMMENT=		FreeType libraries and utilities

META_PACKAGE=		# empty

DEPENDS+=		freetype-lib-${FT_VERS}{,nb[0-9]*}:../../graphics/freetype-lib
DEPENDS+=		freetype-utils-${FT_VERS}{,nb[0-9]*}:../../graphics/freetype-utils

.include "../../mk/bsd.pkg.mk"
