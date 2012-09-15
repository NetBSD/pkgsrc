# $NetBSD: Makefile,v 1.3 2012/09/15 10:06:22 obache Exp $
#

DISTNAME=	dbus-python-1.1.1
PKGNAME=	dbus-python-common-1.1.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/

#BUILD_DEPENDS+= ${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
#DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system
LICENSE=	mit

CONFLICTS+=	py[0-9]*-dbus<1.1.1

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCLUDE_3X= yes

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --disable-html-docs --disable-api-docs

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-std=c9x
.endif

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
