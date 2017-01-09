# $NetBSD: Makefile,v 1.23 2017/01/09 07:55:15 ryoon Exp $
#

DISTNAME=		libvncserver-LibVNCServer-0.9.11
PKGNAME=		libVNCServer-0.9.11
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=LibVNC/}
GITHUB_PROJECT=		libvncserver
GITHUB_TAG=		LibVNCServer-${PKGVERSION_NOREV}

MAINTAINER=		pierrick@bs-network.net
HOMEPAGE=		https://libvnc.github.io/
COMMENT=		Easy API to write one's own vnc server
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		automake

PKGCONFIG_OVERRIDE+=	libvncserver.pc.in
PKGCONFIG_OVERRIDE+=	libvncclient.pc.in

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-sdl-config
CONFIGURE_ARGS+=	--without-x11vnc

PTHREAD_AUTO_VARS=	yes
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure.ac
SUBST_SED.pthread=	-e 's|-lpthread||g'

.include "options.mk"

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
