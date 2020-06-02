# $NetBSD: Makefile,v 1.27 2020/06/02 08:24:34 adam Exp $

DISTNAME=	owncloudclient-2.2.3
PKGREVISION=	14
CATEGORIES=	net
MASTER_SITES=	https://download.owncloud.com/desktop/stable/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://owncloud.com/
COMMENT=	Synchronization program for ownCloud
LICENSE=	gnu-gpl-v2

BROKEN=		"Fails to build with OpenSSL 1.1"

# Do not use libocsync.so from net/ocsync.
CONFLICTS=	ocsync-[0-9]*
CONFLICTS=	mirall-[0-9]*

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# I have no idea about CMake...
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/owncloud

ETCDIR=			etc/ownCloud
MAKE_DIRS+=		${ETCDIR}
EGDIR=			${PREFIX}/share/examples/owncloud
INSTALLATION_DIRS=	${ETCDIR} share/examples/owncloud
CONF_FILES+=		${EGDIR}/sync-exclude.lst \
			${PKG_SYSCONFDIR}/ownCloud/sync-exclude.lst

post-install:
	mv ${DESTDIR}${PKG_SYSCONFDIR}/ownCloud/sync-exclude.lst \
		${DESTDIR}${EGDIR}/sync-exclude.lst

.include "../../mk/dlopen.buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/qt4-qtkeychain/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
