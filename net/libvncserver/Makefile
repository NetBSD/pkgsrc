# $NetBSD: Makefile,v 1.13 2011/10/13 10:50:56 obache Exp $
#

DISTNAME=		LibVNCServer-0.9.8.1
PKGNAME=		libVNCServer-0.9.8.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvncserver/}

MAINTAINER=		pierrick@bs-network.net
HOMEPAGE=		http://libvncserver.sourceforge.net/
COMMENT=		Easy API to write one's own vnc server
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libvncserver.pc.in
PKGCONFIG_OVERRIDE+=	libvncclient.pc.in

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-sdl-config
CONFIGURE_ARGS+=	--without-x11vnc

PTHREAD_AUTO_VARS=	yes
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread||g'

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
