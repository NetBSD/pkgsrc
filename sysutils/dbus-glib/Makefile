# $NetBSD: Makefile,v 1.1.1.1 2004/10/11 17:46:41 jmmv Exp $
#

DBUS_INTERFACE=	glib
DBUS_DIRS=	glib tools

.include "../../sysutils/dbus/Makefile.common"

# We can't install from within the 'tools' directory automatically because
# we'd get a lot of other utilities installed (overriding the ones in the
# dbus package).  We install dbus-monitor by hand below.
INSTALL_DIRS=	${WRKSRC}/glib

INSTALLATION_DIRS=	bin lib/pkgconfig man/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbus-glib-1.pc \
		${PREFIX}/lib/pkgconfig/dbus-glib-1.pc
	cd ${WRKSRC}/tools && ${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} dbus-monitor ${PREFIX}/bin/dbus-monitor
	${INSTALL_DATA} ${WRKSRC}/tools/dbus-monitor.1 \
		${PREFIX}/man/man1/dbus-monitor.1

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
