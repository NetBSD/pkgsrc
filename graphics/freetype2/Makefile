# $NetBSD: Makefile,v 1.31 2004/04/27 14:59:49 adam Exp $
#

DISTNAME=	freetype-2.1.8
PKGNAME=	freetype2-2.1.8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/} \
		ftp://ftp.freetype.org/freetype/freetype2/ \
		ftp://ftp.ntua.gr/mirror/freetype/freetype2/ \
		ftp://ring.aist.go.jp/pub/graphics/freetype/freetype2/ \
		ftp://sunsite.cnlab-switch.ch/mirror/freetype/freetype2/ \
		http://gd.tuwien.ac.at/publishing/freetype/freetype2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.freetype.org/
COMMENT=	Font rendering engine and library API

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
CONFIGURE_DIRS=		${WRKSRC}/builds/unix
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include

PKGCONFIG_OVERRIDE=	builds/unix/freetype2.in

.include "../../mk/bsd.prefs.mk"

.if defined(MKTTINTERP) &&	\
  !empty(MKTTINTERP:M[yY][eE][sS])
CFLAGS+= -DTT_CONFIG_OPTION_BYTECODE_INTERPRETER
.endif
BUILD_DEFS+= MKTTINTERP

post-configure:
	cd ${WRKSRC} && ${LN} -s builds/unix/unix.mk config.mk
.if ${OPSYS} == "IRIX"
	${MKDIR} ${WRKSRC}/.libs
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
