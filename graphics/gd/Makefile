# $NetBSD: Makefile,v 1.27 2001/05/22 09:32:20 wiz Exp $
# FreeBSD Id: Makefile,v 1.2 1997/02/14 07:55:45 asami Exp
#

DISTNAME=       gd-1.8.3
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.boutell.com/gd/
COMMENT=	graphics library for fast PNG creation

DEPENDS+=	freetype-lib>=1.3.1:../../graphics/freetype-lib
DEPENDS+=	png>=1.0.11:../../graphics/png
DEPENDS+=	jpeg-*:../../graphics/jpeg

USE_X11=	YES
USE_XPM=	YES
USE_LIBTOOL=	YES

NO_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-*:../../devel/zlib
CPPFLAGS+=	-I${LOCALBASE}/include				# zlib.h
MAKE_ENV+=	EXTRA_LIBS="-lsocket -lnsl ${LOCALBASE}/lib/libz.a"
.endif

# When the API changes and breaks binary-compatibility with the previous
# version, increment the MAJOR by 1 and reset the MINOR to 0.  Otherwise,
# bump the MINOR when a new version comes out.
#
GD_MAJOR=	1
GD_MINOR=	9
MAKE_ENV+=	GD_MAJOR="${GD_MAJOR}" GD_MINOR="${GD_MINOR}" COMPILER="${CC}"

EVAL_PREFIX+=	XPMDIR=xpm
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include/freetype			# freetype.h
CPPFLAGS+=	-I${LOCALBASE}/include				# png.h
CPPFLAGS+=	-I${XPMDIR}/include -I${XPMDIR}/include/X11	# xpm.h
CPPFLAGS+=	-I${X11BASE}/include

.include "../../mk/bsd.pkg.mk"
