# $NetBSD: Makefile,v 1.9 2005/02/24 01:42:46 dmcmahill Exp $

DISTNAME=	libdv-0.104
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdv/}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://libdv.sourceforge.net/
COMMENT=	DV video codec library

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	${WRKSRC}/libdv.pc.in
PTHREAD_AUTO_VARS=	yes

LIBS+=			${LIBOSSAUDIO}

.include "../../mk/bsd.prefs.mk"
.if empty(MACHINE_PLATFORM:M*-*-i386)
CONFIGURE_ARGS+=	--disable-asm
.endif

.if !exists(${X11BASE}/include/X11/extensions/Xvlib.h)
CONFIGURE_ARGS+=--disable-xv
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
