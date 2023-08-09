# $NetBSD: Makefile,v 1.31 2023/08/09 09:05:11 nia Exp $

DISTNAME=	dbus-python-1.3.2
PKGNAME=	${DISTNAME:S/python/python-common/}
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system
LICENSE=	mit

CONFLICTS+=	py[0-9]*-dbus<1.1.1

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-documentation
CONFIGURE_ARGS+=	PYTHON=${PYTHONBIN}

BUILDLINK_TRANSFORM.SunOS+=	rm:-std=c9x

INSTALLATION_DIRS+=	include/dbus-1.0/dbus
INSTALLATION_DIRS+=	lib/pkgconfig

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/dbus/dbus-python.h \
		${DESTDIR}${PREFIX}/include/dbus-1.0/dbus
	${INSTALL_DATA} ${WRKSRC}/dbus-python.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../lang/python/tool.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.0
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
