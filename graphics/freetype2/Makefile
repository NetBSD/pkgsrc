# $NetBSD: Makefile,v 1.10.2.1 2002/05/11 02:09:10 jlam Exp $
#

DISTNAME=	freetype-2.0.5
PKGNAME=	freetype2-2.0.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/}			\
		http://freetype.sourceforge.net/pub/freetype/freetype2/	\
		http://gd.tuwien.ac.at/publishing/freetype/freetype2/	\
		http://ftp.funet.fi/pub/mirrors/ftp.freetype.org/freetype2/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype2/ \
		ftp://www.nigels.com/pub/freetype/freetype2/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.freetype.org/
COMMENT=	font rendering engine and library API

USE_BUILDLINK2_ONLY=	YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_DIRS=		${WRKSRC}/builds/unix
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/builds/unix/libtool

.include "../../mk/bsd.prefs.mk"

# Check if we got FreeType2 distributed with XFree86 4.x.
.if exists(${X11BASE}/include/freetype2/freetype/freetype.h)
_IS_BUILTIN_FREETYPE2!=	${EGREP} -c BuildFreetype2Library ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_FREETYPE2=	0
.endif

.if ${_IS_BUILTIN_FREETYPE2} != "0"
IGNORE=		"FreeType2 has already been installed as part of XFree86-4.x"
.endif

post-configure:
	cd ${WRKSRC} && ${LN} -s builds/unix/unix.mk config.mk

.include "../../mk/bsd.pkg.mk"
