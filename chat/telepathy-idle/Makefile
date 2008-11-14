# $NetBSD: Makefile,v 1.1.1.1 2008/11/14 23:00:12 wiz Exp $
#

DISTNAME=	telepathy-idle-0.1.2
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-idle/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Components
COMMENT=	Full-featured IRC connection manager for Telepathy

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	OPENSSL_CFLAGS=-I${BUILDLINK_PREFIX.openssl}/include
CONFIGURE_ARGS+=	OPENSSL_LIBS="-L${BUILDLINK_PREFIX.openssl}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib -lssl"

.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
