# $NetBSD: Makefile,v 1.9 2014/12/21 13:46:24 ryoon Exp $

DISTNAME=	mirall-1.7.1
CATEGORIES=	net
MASTER_SITES=	http://download.owncloud.com/desktop/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://owncloud.org/sync-clients/
COMMENT=	Graphicsl file synchronization program for OwnCloud
LICENSE=	gnu-gpl-v2

# Do not use libocsync.so from net/ocsync.
CONFLICTS=	ocsync-[0-9]*

USE_LANGUAGES=	c c++

USE_CMAKE=	yes
OBJDIR=		../build
CONFIGURE_DIRS=	${OBJDIR}
CMAKE_ARG_PATH=	../${DISTNAME}

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

# I have no idea about CMake...
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/owncloud

ETCDIR=			etc/ownCloud
MAKE_DIRS+=		${ETCDIR}
EGDIR=		${PREFIX}/share/examples/mirall
INSTALLATION_DIRS=	${ETCDIR} share/examples/mirall
CONF_FILES+=	${EGDIR}/sync-exclude.lst \
		${PKG_SYSCONFDIR}/ownCloud/sync-exclude.lst

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}

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
