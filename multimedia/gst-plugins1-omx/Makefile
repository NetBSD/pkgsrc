# $NetBSD: Makefile,v 1.3 2016/07/09 06:38:39 wiz Exp $

DISTNAME=	gst-omx-1.2.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-omx/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gstreamer.freedesktop.org/src/gst-omx/
COMMENT=	GStreamer OpenMAX IL wrapper plugin

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake perl
PKGSRC_MAKE_ENV+=	PERL=${PERL5}

EGDIR=			${PREFIX}/share/examples/gst-omx
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg
CONF_FILES+=		${EGDIR}/gstomx.conf \
			${PKG_SYSCONFDIR}/xdg/gstomx.conf
INSTALL_MAKE_FLAGS+=	configdir=${EGDIR:Q}

# Not really arm specific, but misc/raspberrypi-userland is currently the
# only OpenMAX IL implementation in pkgsrc.
ONLY_FOR_PLATFORM=	NetBSD-*-*arm*

# Raspberry Pi target
CONFIGURE_ARGS+=	--with-omx-target=rpi
CFLAGS+=		-I${PREFIX}/include/IL
CFLAGS+=		-I${PREFIX}/include/interface/vcos/pthreads
CFLAGS+=		-I${PREFIX}/include/interface/vmcs_host/linux
LDFLAGS+=		-Wl,-R${PREFIX}/lib -L${PREFIX}/lib
SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_MESSAGE.config=	Fixing plugin config shared library paths.
SUBST_FILES.config=	config/rpi/gstomx.conf
SUBST_SED.config=	-e 's,/opt/vc,${PREFIX},g'
.include "../../misc/raspberrypi-userland/buildlink3.mk"

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.2.0
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
