# $NetBSD: Makefile,v 1.1.1.1 2000/05/07 02:02:23 jlam Exp $

# This package is an alias for ghostscript-x11 to facilitate correct
# dependencies involving older versions of ghostscript for binary packages.

DISTNAME=	ghostscript-${GS_VERS}
GS_VERS=	6.01
CATEGORIES=	print x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org

DEPENDS+=	ghostscript-x11-${GS_VERS}:../../print/ghostscript-x11

USE_X11=	# defined

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_PATCH=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
