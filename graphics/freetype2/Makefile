# $NetBSD: Makefile,v 1.13 2002/10/08 09:25:58 jlam Exp $
#

DISTNAME=	freetype-2.0.5
PKGNAME=	freetype2-2.0.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/}			\
		ftp://ftp.freetype.org/freetype/freetype2/		\
		ftp://ftp.ntua.gr/mirror/freetype/freetype2/		\
		ftp://ring.aist.go.jp/pub/graphics/freetype/freetype2/	\
		ftp://sunsite.cnlab-switch.ch/mirror/freetype/freetype2/ \
		http://gd.tuwien.ac.at/publishing/freetype/freetype2/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.freetype.org/
COMMENT=	font rendering engine and library API

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_DIRS=		${WRKSRC}/builds/unix
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/builds/unix/libtool

post-configure:
	cd ${WRKSRC} && ${LN} -s builds/unix/unix.mk config.mk

.include "../../mk/bsd.pkg.mk"
