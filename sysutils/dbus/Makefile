# $NetBSD: Makefile,v 1.96 2016/02/09 12:56:49 mef Exp $

DISTNAME=	dbus-1.11.0
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Message bus system
LICENSE=	gnu-gpl-v2

CONFLICTS+=	dbus-glib<0.71
CONFLICTS+=	py27-dbus<0.71

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	dbus-1.pc.in

BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/db/dbus ${DBUS_USER} ${DBUS_GROUP} 0755
SPECIAL_PERMS+=		libexec/dbus-daemon-launch-helper ${REAL_ROOT_USER} ${DBUS_GROUP} 4511

SMF_METHODS=	dbus
SMF_NAME=	dbus

MESSAGE_SRC+=	MESSAGE

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}

CONFIGURE_ARGS_GROUPS=	enable disable with without

# Prevent the configure script from picking up a per-user tmp
# directory. See the commit message on revision 1.35
CONFIGURE_ARGS+=	--with-session-socket-dir=/tmp

CONFIGURE_ARGS+=	--without-init-scripts
CONFIGURE_ARGS+=	--disable-ansi
CONFIGURE_ARGS+=	--disable-console-owner-file
CONFIGURE_ARGS+=	--disable-doxygen-docs
CONFIGURE_ARGS+=	--enable-checks
CONFIGURE_ARGS+=	--enable-static

###
### XXX the spawn test hangs, and some of these tests may be bogus
###
#.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
#PKG_OPTIONS.dbus+=		debug
#TEST_TARGET=			check
#.endif

CONFIGURE_ARGS+=	--with-dbus-user=${DBUS_USER}
CONFIGURE_ARGS+=	--with-test-socket-dir=${WRKDIR:Q}

PTHREAD_AUTO_VARS=	yes

.if ${OPSYS} == "Linux"
PLIST.linux=		yes
.else
CONFIGURE_ARGS+=	--disable-abstract-sockets
CONFIGURE_ARGS+=	--disable-selinux
.endif

PLIST_VARS+=    	linux launchd

DBUS_CONF_DIR+=		${PKG_SYSCONFBASE}/dbus-1
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

BUILDLINK_TRANSFORM+=	rm:-Wl,--gc-sections
# Package tries to use these if gcc accepts them, but that doesn't
# mean that we universally can *run* the executables
BUILDLINK_TRANSFORM+=	rm:-fPIE
BUILDLINK_TRANSFORM+=	rm:-pie

.if ${OPSYS} == "OpenBSD"
BUILDLINK_TRANSFORM+=	rm:-lrt
.endif

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/introspect.* \
		${DESTDIR}${PREFIX}/share/doc/dbus/
	${RM} -f ${DESTDIR}${PREFIX}/etc/dbus-1/s*.conf
	${RMDIR} ${DESTDIR}${PREFIX}/etc/dbus-1 || ${TRUE}

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
