# $NetBSD: Makefile,v 1.12.2.1 2002/06/06 06:54:38 jlam Exp $

DISTNAME=		freetype-${FT_VERS}
FT_VERS=		1.3.1
CATEGORIES=		graphics textproc
MASTER_SITES=		#
DISTFILES=		#

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.freetype.org/
COMMENT=		FreeType libraries and utilities

DEPENDS+=		freetype-lib-${FT_VERS}:../../graphics/freetype-lib
DEPENDS+=		freetype-utils-${FT_VERS}:../../graphics/freetype-utils

USE_BUILDLINK2_ONLY=	# defined
USE_X11=		# defined	# freetype-utils uses X11

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_PATCH=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
