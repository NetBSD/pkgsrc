# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:02 tv Exp $
#

DISTNAME=		libdv-0.102
PKGREVISION=		1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libdv/}

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://libdv.sourceforge.net/
COMMENT=		DV video codec library

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBS+=			${PTHREAD_LDFLAGS}
LIBS+=			${LIBOSSAUDIO}

.include "../../mk/bsd.prefs.mk"
.if empty(MACHINE_PLATFORM:M*-*-i386)
CONFIGURE_ARGS+=	--disable-asm
.endif

#if Xfree86 < ver. 4.x.x, uncomment 
#CONFIGURE_ARGS+=--disable-xv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
