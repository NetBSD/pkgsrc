# $NetBSD: Makefile,v 1.9 2016/02/26 10:24:12 jperkin Exp $

DISTNAME=	dbus-python-1.2.0
PKGNAME=	dbus-python-common-1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/

#BUILD_DEPENDS+= ${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
#DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex
#PYTHON_VERSIONS_INCOMPATIBLE=33 34 35 # py-pyrex

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system
LICENSE=	mit

CONFLICTS+=	py[0-9]*-dbus<1.1.1

PYTHON_FOR_BUILD_ONLY=	yes

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --disable-html-docs --disable-api-docs

BUILDLINK_TRANSFORM.SunOS+=	rm:-std=c9x

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/dbus-1.0/dbus
	${INSTALL_DATA} ${WRKSRC}/include/dbus-python.h \
		${DESTDIR}${PREFIX}/include/dbus-1.0/dbus
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/dbus-python.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.0
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_DEPMETHOD.dbus-glib=	build
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
