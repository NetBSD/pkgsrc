# $NetBSD: Makefile,v 1.128 2022/01/27 09:02:58 nros Exp $

DISTNAME=	dbus-1.12.20
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/Software/dbus
COMMENT=	Message bus system
LICENSE=	gnu-gpl-v2

CONFLICTS+=	dbus-glib<0.71
CONFLICTS+=	py27-dbus<0.71

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	dbus-1.pc.in

BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE

OWN_DIRS_PERMS+=	${VARBASE}/lib/dbus ${DBUS_USER} ${DBUS_GROUP} 0755
SPECIAL_PERMS+=		libexec/dbus-daemon-launch-helper ${REAL_ROOT_USER} ${DBUS_GROUP} 4511

SMF_METHODS=	dbus
SMF_NAME=	dbus

.include "../../mk/bsd.prefs.mk"

.if ${INIT_SYSTEM} == "rc.d"
MESSAGE_SRC+=	MESSAGE.rcd
.endif

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}

# Prevent the configure script from picking up a per-user tmp
# directory. See the commit message on revision 1.35
CONFIGURE_ARGS+=	--with-session-socket-dir=/tmp

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

SUBST_CLASSES+=		docbook
SUBST_STAGE.docbook=	pre-configure
SUBST_FILES.docbook=	doc/*.xml*
SUBST_SED.docbook=	-e 's,http://www.oasis-open.org/docbook/xml,${PREFIX}/share/xml/docbook,g'

PTHREAD_AUTO_VARS=	yes

.if ${OPSYS} == "Linux"
# not currently used
#PLIST.linux=		yes
.else
CONFIGURE_ARGS+=	--disable-selinux
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

BUILDLINK_TRANSFORM+=	rm:-Wl,--gc-sections
.if !empty(_PKGSRC_MKPIE:M[Nn][Oo])
# Package tries to use these if gcc accepts them, but that doesn't
# mean that we universally can *run* the executables
BUILDLINK_TRANSFORM+=	rm:-fPIE
BUILDLINK_TRANSFORM+=	rm:-pie
.endif

BUILDLINK_TRANSFORM.OpenBSD+=	rm:-lrt

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/introspect.* \
		${DESTDIR}${PREFIX}/share/doc/dbus/
	${RM} -f ${DESTDIR}${PREFIX}/etc/dbus-1/s*.conf
	${RMDIR} ${DESTDIR}${PREFIX}/etc/dbus-1 || ${TRUE}

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.expat+=	expat>=2.1.0
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
