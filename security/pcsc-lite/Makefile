# $NetBSD: Makefile,v 1.46 2024/06/05 20:25:16 tnn Exp $

DISTNAME=	pcsc-lite-2.2.3
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://pcsclite.apdu.fr/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pcsclite.apdu.fr/
COMMENT=	Middleware to access a smart card using SCard API (PC/SC)
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
# perl for pod2man
USE_TOOLS+=	flex perl pkg-config

.include "../../mk/bsd.prefs.mk"

MESON_ARGS+=	-Dipcdir=${VARBASE}/pcsc-lite
MESON_ARGS+=	-Dlibsystemd=false
MESON_ARGS+=	-Dlibudev=false
MESON_ARGS+=	-Dserialconfdir=${PKG_SYSCONFDIR}/reader.conf.d
MESON_ARGS+=	-Dusbdropdir=${PREFIX}/lib/pcsc-lite/drivers
.if ${OPSYS} != "Linux" && ${OPSYS} != "Darwin"
MESON_ARGS+=	-Dlibusb=true	# use libusb for hotplug
.endif

MAKE_DIRS+=	${VARBASE}/pcsc-lite
MAKE_DIRS+=	${PREFIX}/lib/pcsc-lite
MAKE_DIRS+=	${PREFIX}/lib/pcsc-lite/drivers
MAKE_DIRS+=	${PKG_SYSCONFDIR}/reader.conf.d

EGDIR=			${PREFIX}/share/examples/pcsc-lite

PKGCONFIG_OVERRIDE+=	src/libpcsclite.pc.in
REPLACE_PYTHON+=	src/spy/pcsc-spy

BUILD_DEFS+=		VARBASE
RCD_SCRIPTS=		pcscd

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
