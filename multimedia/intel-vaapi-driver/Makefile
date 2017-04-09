# $NetBSD: Makefile,v 1.2 2017/04/09 10:39:52 leot Exp $

DISTNAME=	intel-vaapi-driver-1.8.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=01org/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/01org/intel-vaapi-driver/
COMMENT=	VA-API user mode driver for Intel GEN Graphics family
LICENSE=	mit

.include "../../multimedia/libva/available.mk"

.if ${VAAPI_AVAILABLE} == "no"
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.endif

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake pkg-config

CONFIGURE_ARGS+=	--disable-wayland

# XXX: Force installation in PREFIX.
# XXX: LIBVA_DRIVERS_PATH - if undefined - is obtained via
# XXX: `pkg-config libva --variable driverdir'. This is not desiderable
# XXX: for native X.org so handle installation similarly to graphics/MesaLib
# XXX: in order to be X11_TYPE agnostic.
CONFIGURE_ENV+=		LIBVA_DRIVERS_PATH=${PREFIX}/lib/dri/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
