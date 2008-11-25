# $NetBSD: Makefile,v 1.5 2008/11/25 23:10:23 jmcneill Exp $
#

DISTNAME=		hal-0.5.11
PKGREVISION=		4
CATEGORIES=		sysutils
MASTER_SITES=		http://hal.freedesktop.org/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		http://hal.freedesktop.org/
COMMENT=		FreeDesktop hardware abstraction layer

BUILD_DEFS+=		VARBASE

HAL_USER?=		haldaemon
HAL_GROUP?=		haldaemon

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.4
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_TOOLS+=		autoconf automake autoreconf
USE_LIBTOOL=		YES

MAKE_DIRS=		${VARBASE}/cache/hald
SPECIAL_PERMS+=		${VARBASE}/cache/hald ${HAL_USER} ${HAL_GROUP} 0644

EGDIR=			${PREFIX}/share/examples/hal

CONF_FILES=		${EGDIR}/hal.conf ${PREFIX}/etc/dbus-1/system.d/hal.conf

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-pci-ids=${PREFIX}/share/pciids
CONFIGURE_ARGS+=	--with-usb-ids=${PREFIX}/share/usbids
CONFIGURE_ARGS+=	--with-hal-user=${HAL_USER}
CONFIGURE_ARGS+=	--with-hal-group=${HAL_GROUP}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--with-eject=/usr/sbin/cdcontrol
CONFIGURE_ARGS+=	--with-backend=freebsd
PLIST_SRC=		PLIST.FreeBSD PLIST
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-[5-9]*)
CONFIGURE_ARGS+=	--with-backend=netbsd
PLIST_SRC=		PLIST.NetBSD PLIST
.endif

.if ${OPSYS} == "Linux"
.include "../../devel/libusb/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
CONFIGURE_ARGS+=	--with-backend=linux
.endif

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
.for halscript in luks-remove luks-setup luks-teardown system-wol-enable system-wol-enabled system-wol-supported
REPLACE_FILES.bash+=	tools/hal-${halscript}
.endfor

RCD_SCRIPTS=		hal

PKG_GROUPS=		${HAL_GROUP}
PKG_USERS=		${HAL_USER}:${HAL_GROUP}
PKG_HOME.haldaemon=	${VARBASE}/run/hal

FILES_SUBST+=		HAL_USER=${HAL_USER}
FILES_SUBST+=		HAL_GROUP=${HAL_GROUP}

post-extract:
	${CP} -r ${FILESDIR}/hald-netbsd ${WRKSRC}/hald/netbsd

pre-configure:
	cd ${WRKSRC} && autoreconf -vi

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libvolume_id/buildlink3.mk"
.include "../../misc/pciids/buildlink3.mk"
.include "../../misc/usbids/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/hal-info/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
