# $NetBSD: Makefile,v 1.28 2016/02/26 10:24:11 jperkin Exp $

CONSOLEKIT_VER=		0.4.6
DISTNAME=		ConsoleKit-${CONSOLEKIT_VER}
PKGNAME=		consolekit-${CONSOLEKIT_VER}
CATEGORIES=		sysutils
MASTER_SITES=		http://www.freedesktop.org/software/ConsoleKit/dist/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
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

CONFIGURE_ARGS.SunOS+=	--enable-rbac-shutdown=solaris.system.shutdown

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
	${INSTALL_SCRIPT} ${FILESDIR}/ck-get-x11-display-device.FreeBSD \
		${DESTDIR}${PREFIX}/libexec/ck-get-x11-display-device
	${INSTALL_SCRIPT} ${FILESDIR}/ck-get-x11-server-pid.FreeBSD \
		${DESTDIR}${PREFIX}/libexec/ck-get-x11-server-pid
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
