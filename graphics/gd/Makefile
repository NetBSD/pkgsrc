# $NetBSD: Makefile,v 1.14 2000/03/21 22:40:52 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1997/02/14 07:55:45 asami Exp
#

DISTNAME=       gd-1.8.1
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.boutell.com/gd/

DEPENDS+=	freetype-*:../../graphics/freetype
DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=	xpm-*:../../graphics/xpm
DEPENDS+=	jpeg-*:../../graphics/jpeg

USE_LIBTOOL=	yes
USE_X11=	yes

NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-*:../../devel/zlib
CPPFLAGS+=	-I${LOCALBASE}/include				# zlib.h
.endif

# When the API changes and breaks binary-compatibility with the previous
# version, increment the MAJOR by 1 and reset the MINOR to 0.  Otherwise,
# bump the MINOR when a new version comes out.
#
GD_MAJOR=	1
GD_MINOR=	8
MAKE_ENV+=	GD_MAJOR="${GD_MAJOR}" GD_MINOR="${GD_MINOR}"

MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include				# png.h
CPPFLAGS+=	-I${X11BASE}/include -I${X11BASE}/include/X11	# xpm.h

.include "../../mk/bsd.pkg.mk"
