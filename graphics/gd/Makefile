# $NetBSD: Makefile,v 1.34 2002/01/21 16:29:25 wiz Exp $
#

DISTNAME=       gd-1.8.4
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.boutell.com/gd/
COMMENT=	graphics library for fast PNG creation

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
REPLACE_PERL=		bdftogd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	EXTRA_LIBS="-lsocket -lnsl"
.endif

CPPFLAGS+=	-I${BUILDLINK_DIR}/include/freetype	# freetype.h
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/X11		# xpm.h

# When the API changes and breaks binary-compatibility with the previous
# version, increment the MAJOR by 1 and reset the MINOR to 0.  Otherwise,
# bump the MINOR when a new version comes out.
#
GD_MAJOR=	1
GD_MINOR=	9
MAKE_ENV+=	GD_MAJOR="${GD_MAJOR}" GD_MINOR="${GD_MINOR}" COMPILER="${CC}"

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
