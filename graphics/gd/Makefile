# $NetBSD: Makefile,v 1.36 2002/08/25 18:39:02 jlam Exp $
#

DISTNAME=       gd-1.8.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.boutell.com/gd/
COMMENT=	graphics library for fast PNG creation

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
REPLACE_PERL=		bdftogd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	EXTRA_LIBS="-lsocket -lnsl"
.endif

CPPFLAGS+=	-I${BUILDLINK_PREFIX.freetype}/include/freetype	# freetype.h
CPPFLAGS+=	-I${BUILDLINK_PREFIX.xpm}/include/X11		# xpm.h

# When the API changes and breaks binary-compatibility with the previous
# version, increment the MAJOR by 1 and reset the MINOR to 0.  Otherwise,
# bump the MINOR when a new version comes out.
#
GD_MAJOR=	1
GD_MINOR=	9
MAKE_ENV+=	GD_MAJOR="${GD_MAJOR}" GD_MINOR="${GD_MINOR}" COMPILER="${CC}"

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
