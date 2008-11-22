# $NetBSD: Makefile,v 1.1.1.1 2008/11/22 03:32:22 jmcneill Exp $
#

CONSOLEKIT_VER=		0.3.0
DISTNAME=		ConsoleKit-${CONSOLEKIT_VER}
PKGNAME=		consolekit-${CONSOLEKIT_VER}
CATEGORIES=		sysutils
MASTER_SITES=		http://people.freedesktop.org/~mccann/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/ConsoleKit
COMMENT=	Framework for defining and tracking users, login sessions, and seats

PKG_SYSCONFSUBDIR=	ConsoleKit

EGDIR=		${PREFIX}/share/examples/consolekit
CONF_FILES+=	${EGDIR}/00-primary.seat ${PKG_SYSCONFDIR}/seats.d/00-primary.seat
CONF_FILES+=	${EGDIR}/ConsoleKit.conf ${PKG_SYSCONFBASE}/dbus-1/system.d/ConsoleKit.conf

MAKE_DIRS=	${PKG_SYSCONFDIR}/seats.d

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		PKG_SYSCONFBASE

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.4
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_TOOLS+=		autoconf automake autoreconf
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

post-extract:
	cp ${FILESDIR}/ck-sysdeps-netbsd.c ${WRKSRC}/src/

pre-configure:
	cd ${WRKSRC} && autoreconf -vi

.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
