# $NetBSD: Makefile,v 1.144 2025/09/03 09:24:42 jperkin Exp $

DISTNAME=	dbus-1.16.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://dbus.freedesktop.org/releases/dbus/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/Software/dbus
COMMENT=	Message bus system
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

CONFLICTS+=	dbus-glib<0.71
CONFLICTS+=	py27-dbus<0.71

USE_TOOLS+=		msgfmt pkg-config
USE_CC_FEATURES=	c99

PKGCONFIG_OVERRIDE+=		output/meson-private/dbus-1.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE

OWN_DIRS_PERMS+=	${VARBASE}/lib/dbus ${DBUS_USER} ${DBUS_GROUP} 0755
SPECIAL_PERMS+=		libexec/dbus-daemon-launch-helper ${REAL_ROOT_USER} ${DBUS_GROUP} 4511

SMF_METHODS=	dbus
SMF_NAME=	dbus

CHECK_PORTABILITY_SKIP+=	tools/cmake-format

.include "../../mk/bsd.prefs.mk"

MESON_ARGS+=		-Ddbus_user=${DBUS_USER}
MESON_ARGS+=		-Dlocalstatedir=${VARBASE}
MESON_ARGS+=		-Dsystem_socket=${VARBASE}/run/dbus/system_bus_socket
MESON_ARGS+=		-Dsystem_pid_file=${VARBASE}/run/dbus/pid
MESON_ARGS+=		-Ddoxygen_docs=disabled

LDFLAGS.SunOS+=		-lsocket -lnsl

SUBST_CLASSES+=		docbook
SUBST_STAGE.docbook=	pre-configure
SUBST_FILES.docbook=	doc/*.xml*
SUBST_SED.docbook=	-e 's,http://www.oasis-open.org/docbook/xml,${PREFIX}/share/xml/docbook,g'

.if ${OPSYS} == "SunOS"
MESON_ARGS+=		-Dinotify=disabled
MESON_ARGS+=		-Dsolaris_console_owner_file="/dev/vt/console_user"
.endif

DBUS_CONF_DIR=		${PKG_SYSCONFBASE}/dbus-1
OWN_DIRS+=		${DBUS_CONF_DIR}/services
OWN_DIRS+=		${DBUS_CONF_DIR}/system-services
OWN_DIRS+=		${DBUS_CONF_DIR}/session.d
OWN_DIRS+=		${DBUS_CONF_DIR}/system.d

RCD_SCRIPTS=		dbus

PKG_GROUPS_VARS+=	DBUS_GROUP
PKG_USERS_VARS+=	DBUS_USER

PKG_GROUPS=		${DBUS_GROUP}
PKG_USERS=		${DBUS_USER}:${DBUS_GROUP}
PKG_GECOS.${DBUS_USER}=	System message bus
PKG_HOME.${DBUS_USER}=	${VARBASE}/run/dbus

FILES_SUBST+=		DBUS_USER=${DBUS_USER}
FILES_SUBST+=		DBUS_GROUP=${DBUS_GROUP}

BUILDLINK_TRANSFORM.FreeBSD+=	rm:-Wl,--no-undefined
BUILDLINK_TRANSFORM+=		rm:-Wl,--gc-sections
.if !empty(_PKGSRC_MKPIE:M[Nn][Oo])
# Package tries to use these if gcc accepts them, but that doesn't
# mean that we universally can *run* the executables
BUILDLINK_TRANSFORM+=		rm:-fPIE
BUILDLINK_TRANSFORM+=		rm:-pie
.endif

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/introspect.* \
		${DESTDIR}${PREFIX}/share/doc/dbus/
	${RM} -f ${DESTDIR}${PREFIX}/etc/dbus-1/s*.conf
	${RMDIR} ${DESTDIR}${PREFIX}/etc/dbus-1 || ${TRUE}

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.expat+=	expat>=2.1.0
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
