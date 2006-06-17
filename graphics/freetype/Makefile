# $NetBSD: Makefile,v 1.26 2006/06/17 19:41:33 minskim Exp $

DISTNAME=		freetype-${FT_VERS}
FT_VERS=		1.5
CATEGORIES=		graphics meta-pkgs textproc
MASTER_SITES=		#
DISTFILES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freetype.org/
COMMENT=		FreeType libraries and utilities

DEPENDS+=		freetype-lib-${FT_VERS}:../../graphics/freetype-lib
DEPENDS+=		freetype-utils-${FT_VERS}:../../graphics/freetype-utils

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
