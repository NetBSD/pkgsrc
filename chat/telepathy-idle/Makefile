# $NetBSD: Makefile,v 1.58 2024/05/29 16:31:33 adam Exp $

DISTNAME=	telepathy-idle-0.1.8
PKGREVISION=	27
CATEGORIES=	chat
MASTER_SITES=	https://telepathy.freedesktop.org/releases/telepathy-idle/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://telepathy.freedesktop.org/wiki/Components
COMMENT=	Full-featured IRC connection manager for Telepathy
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.1.8

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

.include "../../lang/python/batteries-included.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
