# $NetBSD: Makefile,v 1.19 2004/04/24 22:46:10 jlam Exp $

DISTNAME=		freetype-${FT_VERS}
FT_VERS=		1.3.1
PKGREVISION=		1
CATEGORIES=		graphics textproc
MASTER_SITES=		#
DISTFILES=		#

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.freetype.org/
COMMENT=		FreeType libraries and utilities

DEPENDS+=		freetype-lib-${FT_VERS}nb1:../../graphics/freetype-lib
DEPENDS+=		freetype-utils-${FT_VERS}:../../graphics/freetype-utils

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined
NO_BUILDLINK=		# defined

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
