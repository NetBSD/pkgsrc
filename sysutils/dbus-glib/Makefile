# $NetBSD: Makefile,v 1.2 2004/10/12 08:30:46 jmmv Exp $
#

DBUS_INTERFACE=	glib
DBUS_DIRS=	dbus glib tools

.include "../../sysutils/dbus/Makefile.common"

PKGREVISION=	1

# We can't install from within the 'dbus' nor 'tools' directory automatically
# because we'd get a lot of other stuff installed (overriding files in the
# dbus package).
INSTALL_DIRS=	${WRKSRC}/glib

INSTALLATION_DIRS=	bin lib/pkgconfig man/man1

PRINT_PLIST_AWK+=	/^@dirrm include\/dbus-1.0\/dbus$$/ \
				{ print "@comment in dbus: " $$0; next; }

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/dbus-1.0/dbus
	${INSTALL_DATA} ${WRKSRC}/dbus/dbus-glib*.h \
		${PREFIX}/include/dbus-1.0/dbus
	${INSTALL_DATA} ${WRKSRC}/dbus-glib-1.pc \
		${PREFIX}/lib/pkgconfig/dbus-glib-1.pc
	cd ${WRKSRC}/tools && ${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} dbus-monitor ${PREFIX}/bin/dbus-monitor
	${INSTALL_DATA} ${WRKSRC}/tools/dbus-monitor.1 \
		${PREFIX}/man/man1/dbus-monitor.1

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
