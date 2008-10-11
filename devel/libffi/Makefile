# $NetBSD: Makefile,v 1.8 2008/10/11 22:33:56 dholland Exp $
#

DISTNAME=	libffi-3.0.6
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/libffi/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://sources.redhat.com/libffi/
COMMENT=	Foreign function interface

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
INFO_FILES=	# PLIST

PKGCONFIG_OVERRIDE+=	libffi.pc.in

.include "../../mk/bsd.pkg.mk"
