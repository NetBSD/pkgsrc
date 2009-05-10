# $NetBSD: Makefile,v 1.14 2009/05/10 10:30:18 zafer Exp $
#

DISTNAME=	dbus-python-0.83.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/

BUILD_DEPENDS+= ${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes

PYTHON_VERSIONS_ACCEPTED=	26 25 24
PY_PATCHPLIST=			YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.0
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
# py-libxml2 is only needed at runtime
.include "../../textproc/py-libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
