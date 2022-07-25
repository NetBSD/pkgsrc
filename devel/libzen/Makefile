# $NetBSD: Makefile,v 1.6 2022/07/25 11:12:23 wiz Exp $

DISTNAME=	libzen_0.4.31
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zenlib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/zenlib/
COMMENT=	Small C++ derivate class to have a simpler life
LICENSE=	zlib

WRKSRC=		${WRKDIR}/ZenLib
USE_TOOLS+=	autoconf automake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

REPLACE_SH=		Project/GNU/Library/libzen-config.in

PKGCONFIG_OVERRIDE+=	Project/GNU/Library/libzen.pc.in

CONFIGURE_DIRS+=	Project/GNU/Library

.include "../../mk/bsd.prefs.mk"
# Enable shared library
.if empty(SHLIB_TYPE:Mnone)
CONFIGURE_ARGS+=	--enable-shared
.endif

pre-configure:
	cd ${WRKSRC}/${CONFIGURE_DIRS} && autoreconf -i

.include "../../mk/bsd.pkg.mk"
