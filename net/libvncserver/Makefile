# $NetBSD: Makefile,v 1.19 2013/12/17 16:27:18 prlw1 Exp $
#

DISTNAME=		LibVNCServer-0.9.9
PKGNAME=		libVNCServer-0.9.9
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvncserver/}

MAINTAINER=		pierrick@bs-network.net
HOMEPAGE=		http://libvncserver.sourceforge.net/
COMMENT=		Easy API to write one's own vnc server
LICENSE=		gnu-gpl-v2

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
