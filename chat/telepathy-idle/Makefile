# $NetBSD: Makefile,v 1.24 2012/10/03 00:02:45 asau Exp $
#

DISTNAME=	telepathy-idle-0.1.8
PKGREVISION=	6
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-idle/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Components
COMMENT=	Full-featured IRC connection manager for Telepathy
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

LDFLAGS.DragonFly=	-lcrypto
LDFLAGS.SunOS+=		-lcrypto

CONFIGURE_ARGS+=	OPENSSL_CFLAGS=-I${BUILDLINK_PREFIX.openssl}/include
CONFIGURE_ARGS+=	OPENSSL_LIBS="-L${BUILDLINK_PREFIX.openssl}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib -lssl"

CONFIGURE_ENV+=		ac_cv_prog_PYTHON=${PYTHONBIN}
# needs py-twisted
# TEST_TARGET= check

.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
