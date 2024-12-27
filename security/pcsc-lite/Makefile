# $NetBSD: Makefile,v 1.50 2024/12/27 12:37:28 gdt Exp $

DISTNAME=	pcsc-lite-2.3.1
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
.include "options.mk"

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

LDFLAGS.SunOS+=	-lsocket

EGDIR=			${PREFIX}/share/examples/pcsc-lite

PKGCONFIG_OVERRIDE+=	src/libpcsclite.pc.in
REPLACE_PYTHON+=	src/spy/pcsc-spy

BUILD_DEFS+=		VARBASE
RCD_SCRIPTS=		pcscd

# Reported upstream by email 20241227.  New "default" config file
# installed in Linuxy place.  For now, hackily move it to be an
# example,
post-install:
	${MKDIR} -p ${DESTDIR}${PREFIX}/share/examples/pcsc-lite
	${MV} ${DESTDIR}${PREFIX}/etc/default/pcscd \
	      ${DESTDIR}${PREFIX}/share/examples/pcsc-lite
	${RMDIR} ${DESTDIR}${PREFIX}/etc/default
	${RMDIR} ${DESTDIR}${PREFIX}/etc

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
