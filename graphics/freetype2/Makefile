# $NetBSD: Makefile,v 1.22 2003/09/15 08:48:41 adam Exp $
#

DISTNAME=	freetype-2.1.5
PKGNAME=	freetype2-2.1.5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freetype.org/freetype/freetype2/		\
		ftp://ftp.ntua.gr/mirror/freetype/freetype2/		\
		ftp://ring.aist.go.jp/pub/graphics/freetype/freetype2/	\
		ftp://sunsite.cnlab-switch.ch/mirror/freetype/freetype2/ \
		http://gd.tuwien.ac.at/publishing/freetype/freetype2/
# comment out sf: contains different 2.1.4 tarball with same contents
# ${MASTER_SITE_SOURCEFORGE:=freetype/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.freetype.org/
COMMENT=	Font rendering engine and library API

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_DIRS=		${WRKSRC}/builds/unix
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include
CONFIGURE_ENV+=		RPATH_FLAG="${RPATH_FLAG}"

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/builds/unix/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/builds/unix/freetype2.in

.include "../../mk/bsd.prefs.mk"

post-configure:
	cd ${WRKSRC} && ${LN} -s builds/unix/unix.mk config.mk
.if ${OPSYS} == "IRIX"
	${MKDIR} ${WRKSRC}/.libs
.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
