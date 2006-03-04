# $NetBSD: Makefile,v 1.25 2006/03/04 21:29:47 jlam Exp $

DISTNAME=		freetype-${FT_VERS}
FT_VERS=		1.3.1
PKGREVISION=		3
CATEGORIES=		graphics meta-pkgs textproc
MASTER_SITES=		#
DISTFILES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freetype.org/
COMMENT=		FreeType libraries and utilities

DEPENDS+=		freetype-lib-${FT_VERS}nb3:../../graphics/freetype-lib
DEPENDS+=		freetype-utils-${FT_VERS}nb2:../../graphics/freetype-utils

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
