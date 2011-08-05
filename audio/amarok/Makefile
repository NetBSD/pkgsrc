# $NetBSD: Makefile,v 1.98 2011/08/05 14:21:31 abs Exp $
#

DISTNAME=	amarok-${VERS}
VERS=		2.4.0
PKGREVISION=	3
CATEGORIES=	audio multimedia
#MASTER_SITES=	http://download.kde.org/unstable/amarok/${VERS}/src/ \
#		ftp://gd.tuwien.ac.at/kde/unstable/amarok/${VERS}/src/
MASTER_SITES=	http://download.kde.org/stable/amarok/${VERS}/src/ \
		ftp://gd.tuwien.ac.at/kde/stable/amarok/${VERS}/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://amarok.kde.org/
COMMENT=	KDE4 audio player
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2.1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	moodbar-[0-9]*:../../audio/moodbar

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

CMAKE_ARGS+=	-DMYSQL_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.mysql-client}/include/mysql
CMAKE_ARGS+=	-DMYSQL_EMBEDDED_LIBRARIES:PATH=${BUILDLINK_PREFIX.mysql-server}/lib/mysql/libmysqld.a
CMAKE_ARGS+=	-DMYSQL_EMBEDDED_FOUND:BOOL=TRUE
CMAKE_ARGS+=	-DHAVE_MYSQL_OPT_EMBEDDED_CONNECTION:BOOL=TRUE
CMAKE_ARGS+=	-DMYSQL_LIBRARIES:PATH=${BUILDLINK_PREFIX.mysql-client}/lib/mysql/libmysqlclient.so

SUBST_CLASSES+=		mysql
SUBST_STAGE.mysql=	post-patch
SUBST_MESSAGE.mysql=	Fixup paths for MySQL embedded
SUBST_FILES.mysql=	cmake/modules/FindMySQLAmarok.cmake
SUBST_FILES.mysql+=	src/core-impl/collections/db/sql/mysqlecollection/CMakeLists.txt
SUBST_SED.mysql=	-e s:/opt/mysqle/:${BUILDLINK_PREFIX.mysql-server}:
# Additional SUBST_SED.mysql added later based on mysql server version

.include "options.mk"

.include "../../mk/mysql.buildlink3.mk"
.if ${_MYSQL_VERSION} == "55"
.include "../../databases/mysql55-server/buildlink3.mk"
SUBST_SED.mysql+=	-e s:@@WLR@@:${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-server}/lib:
.elif ${_MYSQL_VERSION} == "51"
DEPENDS+=	mysql-server-[0-9]*:../../databases/mysql51-server
SUBST_SED.mysql+=	-e s:@@WLR@@:${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-server}/lib/mysql:
.else
DEPENDS+=	mysql-server-[0-9]*:../../databases/mysql5-server
SUBST_SED.mysql+=	-e s:@@WLR@@:${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-server}/lib/mysql:
.endif

.include "../../audio/liblastfm/buildlink3.mk"
.include "../../audio/libofa/buildlink3.mk"
BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.6nb1
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/taglib-extras/buildlink3.mk"
.include "../../devel/qtscriptgenerator/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/kdemultimedia4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
# for plasma
.include "../../x11/kdebase-workspace4/buildlink3.mk"
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs4>=4.5.0
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
