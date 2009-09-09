# $NetBSD: Makefile,v 1.8 2009/09/09 11:16:56 wiz Exp $
#

DISTNAME=	telepathy-idle-0.1.4
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-idle/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Components
COMMENT=	Full-featured IRC connection manager for Telepathy
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	OPENSSL_CFLAGS=-I${BUILDLINK_PREFIX.openssl}/include
CONFIGURE_ARGS+=	OPENSSL_LIBS="-L${BUILDLINK_PREFIX.openssl}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib -lssl"

.include "../../lang/python/pyversion.mk"
.if ${PYPKGPREFIX} == "py24"
BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
.endif
CONFIGURE_ENV+=		ac_cv_prog_PYTHON=${PYTHONBIN}

.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
