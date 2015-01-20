# $NetBSD: Makefile,v 1.78 2015/01/20 23:45:35 wiz Exp $

DISTNAME=	dbus-1.8.14
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Message bus system
LICENSE=	gnu-gpl-v2

CONFLICTS+=	dbus-glib<0.71
CONFLICTS+=	py26-dbus<0.71
CONFLICTS+=	py27-dbus<0.71

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	dbus-1.pc.in

BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/db/dbus ${DBUS_USER} ${DBUS_GROUP} 0755
SPECIAL_PERMS+=		libexec/dbus-daemon-launch-helper ${REAL_ROOT_USER} ${DBUS_GROUP} 4511

SMF_METHODS=	dbus
SMF_NAME=	dbus

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CONFIGURE_ARGS_GROUPS=	enable disable with without

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-launchd-agent-dir=${PREFIX}/Library/LaunchAgents
CONFIGURE_ARGS+=	--with-session-socket-dir=/tmp
.endif

CONFIGURE_ARGS.Linux=	abstract-sockets selinux
CONFIGURE_ARGS.docs=	doxygen-docs xml-docs

CONFIGURE_ARGS.without+=	init-scripts
CONFIGURE_ARGS.disable=		ansi
CONFIGURE_ARGS.disable+=	console-owner-file
CONFIGURE_ARGS.disable+=	${CONFIGURE_ARGS.docs}
CONFIGURE_ARGS.enable=		checks static
###
### XXX the spawn test hangs, and some of these tests may be bogus
###
#.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
#PKG_OPTIONS.dbus+=		debug
#TEST_TARGET=			check
#.endif

CONFIGURE_ARGS.with=	dbus-user=${DBUS_USER}
CONFIGURE_ARGS.with+=	test-socket-dir=${WRKDIR:Q}

PTHREAD_AUTO_VARS=	yes

.if ${OPSYS} == "Linux"
PLIST.linux=		yes
.else
CONFIGURE_ARGS.disable+=\
			${CONFIGURE_ARGS.Linux}
.endif

PLIST_VARS+=    	linux

CONFIGURE_ARGS+=\
	${CONFIGURE_ARGS_GROUPS:@.g.@			\
		${CONFIGURE_ARGS.${.g.}:@.a.@		\
			--${.g.}-${.a.}			\
		@}					\
	@:M*}

MAKE_DIRS=		${PKG_SYSCONFDIR}/dbus-1/event.d
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dbus-1/system.d
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dbus-1/session.d

EGDIR=			${PREFIX}/share/examples/dbus
CONF_FILES=	${EGDIR}/session.conf ${PKG_SYSCONFDIR}/dbus-1/session.conf
CONF_FILES+=	${EGDIR}/system.conf ${PKG_SYSCONFDIR}/dbus-1/system.conf

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

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
