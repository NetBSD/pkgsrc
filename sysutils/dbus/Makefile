# $NetBSD: Makefile,v 1.14.2.1 2006/12/20 17:15:36 ghen Exp $
#

DISTNAME=	dbus-0.92
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://freedesktop.org/software/dbus/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Message bus system

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
CONFIGURE_ARGS+=	--without-x

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbus
PKG_SUPPORTED_OPTIONS+=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-asserts
CONFIGURE_ARGS+=	--enable-tests
CONFIGURE_ARGS+=	--enable-verbose-mode
.endif

# Next version will automatically detect this with a sane configure check,
# so it should go away.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--enable-kqueue
.endif

PKG_SYSCONFSUBDIR=	dbus-1
MAKE_DIRS=		${PKG_SYSCONFDIR}/event.d
MAKE_DIRS+=		${PKG_SYSCONFDIR}/system.d

EGDIR=			${PREFIX}/share/examples/dbus
CONF_FILES=		${EGDIR}/session.conf ${PKG_SYSCONFDIR}/session.conf
CONF_FILES+=		${EGDIR}/system.conf ${PKG_SYSCONFDIR}/system.conf

RCD_SCRIPTS=		dbus

PKG_GROUPS=		messagebus
PKG_USERS=		messagebus:messagebus
PKG_GECOS.messagebus=	System message bus
PKG_HOME.messagebus=	${VARBASE}/run/dbus

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
