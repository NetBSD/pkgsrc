# $NetBSD: Makefile,v 1.4 2013/11/23 03:00:18 ryoon Exp $

DISTNAME=	mirall-1.4.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.owncloud.com/desktop/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://owncloud.org/sync-clients/
COMMENT=	Graphicsl file synchronization program for OwnCloud
LICENSE=	gnu-gpl-v2

CFLAGS+=	-g

USE_LANGUAGES=	c c++

USE_CMAKE=	yes
OBJDIR=		../build
CONFIGURE_DIRS=	${OBJDIR}
CMAKE_ARG_PATH=	../${DISTNAME}

FIND_PREFIX:=   OCSYNCDIR=ocsync
.include "../../mk/find-prefix.mk"

CMAKE_ARGS+=	-DCSYNC_BUILD_PATH=${OCSYNCDIR}/bin
CMAKE_ARGS+=	-DCSYNC_LIBRARY_PATH=${OCSYNCDIR}/lib
CMAKE_ARGS+=	-DCSYNC_INCLUDE_PATH=${OCSYNCDIR}/include/ocsync

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

LDFLAGS.NetBSD+=	-linotify

ETCDIR=			etc/OwnCloud
MAKE_DIRS+=		${ETCDIR}
INSTALLATION_DIRS=	${ETCDIR}
EGDIR=		${PREFIX}/share/examples/mirall
CONF_FILES+=	${EGDIR}/sync-exclude.lst \
		${PKG_SYSCONFDIR}/OwnCloud/sync-exclude.lst

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/ocsync/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
