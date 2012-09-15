# $NetBSD: Makefile,v 1.62 2012/09/15 10:06:27 obache Exp $

DISTNAME=		hal-0.5.14
PKGREVISION=		8
CATEGORIES=		sysutils
MASTER_SITES=		http://hal.freedesktop.org/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		netbsd-desktop@NetBSD.org
HOMEPAGE=		http://hal.freedesktop.org/
COMMENT=		FreeDesktop hardware abstraction layer
LICENSE=		gnu-gpl-v2

BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_TOOLS+=		autoconf automake autoreconf
USE_LIBTOOL=		YES

MAKE_DIRS+=		/media
MAKE_DIRS+=		${VARBASE}/cache/hald
SPECIAL_PERMS+=		${VARBASE}/cache/hald ${HAL_USER} ${HAL_GROUP} 0644

EGDIR=			${PREFIX}/share/examples/hal

CONF_FILES=		${EGDIR}/hal.conf ${PKG_SYSCONFBASE}/dbus-1/system.d/hal.conf

CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-pci-ids=${PREFIX}/share/pciids
CONFIGURE_ARGS+=	--with-usb-ids=${PREFIX}/share/usbids
CONFIGURE_ARGS+=	--without-os-type

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
.include "../../devel/libvolume_id/buildlink3.mk"
CONFIGURE_ARGS+=	--with-eject=/usr/sbin/cdcontrol
CONFIGURE_ARGS+=	--with-backend=freebsd
PLIST_SRC=		PLIST.DragonFly PLIST

.elif ${OPSYS} == "FreeBSD"
.include "../../devel/libvolume_id/buildlink3.mk"
CONFIGURE_ARGS+=	--with-eject=/usr/sbin/cdcontrol
CONFIGURE_ARGS+=	--with-backend=freebsd
PLIST_SRC=		PLIST.FreeBSD PLIST

.elif !empty(MACHINE_PLATFORM:MNetBSD-[5-9]*)
.include "../../devel/libvolume_id/buildlink3.mk"
CONFIGURE_ARGS+=	--with-backend=netbsd
HAL_GROUP=		operator

.elif ${OPSYS} == "Linux"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libblkid/buildlink3.mk"
.include "../../devel/libvolume_id/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
CONFIGURE_ARGS+=	--with-backend=linux
MAKE_DIRS+=		${PKG_SYSCONFBASE}/udev
MAKE_DIRS+=		${PKG_SYSCONFBASE}/udev/rules.d
CONF_FILES+=		${EGDIR}/90-hal.rules \
			${PKG_SYSCONFBASE}/udev/rules.d/90-hal.rules

.else	# Unsupported systems
# Pull in the dummy backend
.include "../../devel/libvolume_id/buildlink3.mk"
CONFIGURE_ARGS+=	--with-backend=dummy
PLIST_SRC=		PLIST
.endif

CFLAGS.SunOS+=		-Du_int32_t=uint32_t

.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--as-needed
.endif

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
.for halscript in luks-remove luks-setup luks-teardown system-wol-enable system-wol-enabled system-wol-supported
REPLACE_FILES.bash+=	tools/hal-${halscript}
.endfor

HAL_USER?=		haldaemon
HAL_GROUP?=		haldaemon
CONFIGURE_ARGS+=	--with-hal-user=${HAL_USER}
CONFIGURE_ARGS+=	--with-hal-group=${HAL_GROUP}
CONFIGURE_ARGS+=	--disable-pmu

RCD_SCRIPTS=		hal

.if ${HAL_GROUP} != "operator"
PKG_GROUPS=		${HAL_GROUP}
.endif
PKG_USERS=		${HAL_USER}:${HAL_GROUP}
PKG_HOME.haldaemon=	${VARBASE}/run/hal

FILES_SUBST+=		HAL_USER=${HAL_USER}
FILES_SUBST+=		HAL_GROUP=${HAL_GROUP}

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

TEST_TARGET=		check

post-extract:
	${CP} -r ${FILESDIR}/hald-netbsd ${WRKSRC}/hald/netbsd
	${CP} -r ${FILESDIR}/tools-netbsd ${WRKSRC}/tools/netbsd

pre-configure:
	cd ${WRKSRC} && autoreconf -vi ${AUTORECONF_ARGS}

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../misc/pciids/buildlink3.mk"
.include "../../misc/usbids/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/hal-info/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
