# $NetBSD: Makefile,v 1.30 2011/04/26 11:52:51 joerg Exp $

DISTNAME=		freetype-${FT_VERS}
FT_VERS=		1.5
CATEGORIES=		graphics meta-pkgs textproc

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freetype.org/
COMMENT=		FreeType libraries and utilities

META_PACKAGE=		# empty

DEPENDS+=		freetype-lib-${FT_VERS}{,nb[0-9]*}:../../graphics/freetype-lib
DEPENDS+=		freetype-utils-${FT_VERS}{,nb[0-9]*}:../../graphics/freetype-utils

.include "../../mk/bsd.pkg.mk"
