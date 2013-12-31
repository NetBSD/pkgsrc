# $NetBSD: Makefile,v 1.1 2013/12/31 23:10:21 ryoon Exp $

DISTNAME=	libzen_0.4.29
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zenlib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/zenlib/files/ZenLib%20-%20Sources/0.4.29/
COMMENT=	ZenLib, Small C++ derivate class to have a simpler life
LICENSE=	zlib

WRKSRC=		${WRKDIR}/ZenLib
USE_TOOLS+=	autoconf automake pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

REPLACE_SH=		Project/GNU/Library/libzen-config.in

PKGCONFIG_OVERRIDE+=	Project/GNU/Library/libzen.pc.in

CONFIGURE_DIRS+=	Project/GNU/Library

# Enable shared library
.if empty(SHLIB_TYPE:Mnone)
CONFIGURE_ARGS+=	--enable-shared
.endif

pre-configure:
	cd ${WRKSRC}/${CONFIGURE_DIRS} && autoreconf -i

.include "../../mk/bsd.pkg.mk"
