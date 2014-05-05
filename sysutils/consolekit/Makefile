# $NetBSD: Makefile,v 1.22 2014/05/05 21:19:40 ryoon Exp $
#

CONSOLEKIT_VER=		0.3.0
DISTNAME=		ConsoleKit-${CONSOLEKIT_VER}
PKGNAME=		consolekit-${CONSOLEKIT_VER}
PKGREVISION=		11
CATEGORIES=		sysutils
MASTER_SITES=		http://www.freedesktop.org/software/ConsoleKit/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=	netbsd-desktop@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/ConsoleKit
COMMENT=	Framework for defining and tracking users, login sessions, and seats
LICENSE=	gnu-gpl-v2

PKG_SYSCONFSUBDIR=	ConsoleKit

EGDIR=		${PREFIX}/share/examples/consolekit
CONF_FILES+=	${EGDIR}/00-primary.seat ${PKG_SYSCONFDIR}/seats.d/00-primary.seat
CONF_FILES+=	${EGDIR}/ConsoleKit.conf ${PKG_SYSCONFBASE}/dbus-1/system.d/ConsoleKit.conf

MAKE_DIRS=	${PKG_SYSCONFDIR}/seats.d

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		PKG_SYSCONFBASE

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_TOOLS+=		autoconf automake autoreconf
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

# TODO
#CONFIGURE_ARGS+=	--enable-pam-module
#.include "../../mk/pam.buildlink3.mk"

post-extract:
	${CP} ${FILESDIR}/ck-sysdeps-netbsd.c ${WRKSRC}/src/
	${CP} ${FILESDIR}/ck-sysdeps-openbsd.c ${WRKSRC}/src/

pre-configure:
	cd ${WRKSRC} && autoreconf -vi ${AUTORECONF_ARGS}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
post-install:
	${CP} ${FILESDIR}/ck-get-x11-display-device.FreeBSD \
		${DESTDIR}${PREFIX}/libexec/ck-get-x11-display-device
	${CP} ${FILESDIR}/ck-get-x11-server-pid.FreeBSD \
		${DESTDIR}${PREFIX}/libexec/ck-get-x11-server-pid
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-rbac-shutdown=solaris.system.shutdown
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
