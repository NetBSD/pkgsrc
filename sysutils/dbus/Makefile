# $NetBSD: Makefile,v 1.26 2008/02/08 23:15:16 bjs Exp $
#

DISTNAME=	dbus-1.0.2
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Message bus system

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	dbus-glib<0.71
CONFLICTS+=	py*-dbus<0.71

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	dbus-1.pc.in

CONFIGURE_ARGS+=	--disable-abstract-sockets
CONFIGURE_ARGS+=	--disable-ansi
CONFIGURE_ARGS+=	--disable-asserts
CONFIGURE_ARGS+=	--disable-console-owner-file
CONFIGURE_ARGS+=	--disable-dnotify
CONFIGURE_ARGS+=	--disable-doxygen-docs
CONFIGURE_ARGS+=	--disable-gcov
CONFIGURE_ARGS+=	--disable-selinux
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--disable-verbose-mode
CONFIGURE_ARGS+=	--disable-xml-docs
CONFIGURE_ARGS+=	--enable-checks
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-xml=expat
CONFIGURE_ARGS+=	--with-dbus-user=${DBUS_USER}

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbus
PKG_SUPPORTED_OPTIONS+=	debug nox11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-asserts
CONFIGURE_ARGS+=	--enable-tests
CONFIGURE_ARGS+=	--enable-verbose-mode
.endif

.if !empty(PKG_OPTIONS:Mnox11)
CONFIGURE_ARGS+=	--without-x
.else
.include "../../x11/libX11/buildlink3.mk"
.endif

PKG_SYSCONFSUBDIR=	dbus-1
MAKE_DIRS=		${PKG_SYSCONFDIR}/event.d
MAKE_DIRS+=		${PKG_SYSCONFDIR}/system.d

EGDIR=			${PREFIX}/share/examples/dbus
CONF_FILES=		${EGDIR}/session.conf ${PKG_SYSCONFDIR}/session.conf
CONF_FILES+=		${EGDIR}/system.conf ${PKG_SYSCONFDIR}/system.conf
INSTALLATION_DIRS=	${EGDIR}

RCD_SCRIPTS=		dbus

PKG_GROUPS_VARS+=	DBUS_GROUP
PKG_USERS_VARS+=	DBUS_USER

PKG_GROUPS=		${DBUS_GROUP}
PKG_USERS=		${DBUS_USER}:${DBUS_GROUP}
PKG_GECOS.${DBUS_USER}=	System message bus
PKG_HOME.${DBUS_USER}=	${VARBASE}/run/dbus

FILES_SUBST+=		DBUS_USER=${DBUS_USER}
FILES_SUBST+=		DBUS_GROUP=${DBUS_GROUP}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
