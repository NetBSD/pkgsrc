# $NetBSD: Makefile,v 1.79 2010/02/16 09:01:46 wiz Exp $
#

DISTNAME=	amarok-${VERS}
VERS=		2.2.2
PKGREVISION=	3
CATEGORIES=	audio multimedia
#MASTER_SITES=	http://download.kde.org/unstable/amarok/${VERS}/src/ \
#		ftp://gd.tuwien.ac.at/kde/unstable/amarok/${VERS}/src/
MASTER_SITES=	http://download.kde.org/stable/amarok/${VERS}/src/ \
		ftp://gd.tuwien.ac.at/kde/stable/amarok/${VERS}/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://amarok.kde.org/
COMMENT=	KDE4 audio player
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2.1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	moodbar-[0-9]*:../../audio/moodbar

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

CMAKE_ARGS+=	-DMYSQL_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.mysql-embedded}/mysqld/include/mysql
CMAKE_ARGS+=	-DMYSQL_EMBEDDED_LIBRARIES:PATH=${BUILDLINK_PREFIX.mysql-embedded}/mysqld/lib/mysql/libmysqld.a
CMAKE_ARGS+=	-DMYSQL_EMBEDDED_FOUND:BOOL=TRUE
CMAKE_ARGS+=	-DHAVE_MYSQL_OPT_EMBEDDED_CONNECTION:BOOL=TRUE
CMAKE_ARGS+=	-DMYSQL_LIBRARIES:PATH=${BUILDLINK_PREFIX.mysql-embedded}/mysqld/lib/mysql/libmysqlclient.so

SUBST_CLASSES+=		mysql
SUBST_STAGE.mysql=	post-patch
SUBST_MESSAGE.mysql=	Fixup paths for MySQL embedded
SUBST_FILES.mysql=	cmake/modules/FindMySQLAmarok.cmake
SUBST_FILES.mysql+=	src/collection/mysqlecollection/CMakeLists.txt
SUBST_SED.mysql=	-e s:/opt/mysqle/:${BUILDLINK_PREFIX.mysql-embedded}/mysqld:
SUBST_SED.mysql+=	-e s:@@WLR@@:${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-embedded}/mysqld/lib/mysql:

.include "options.mk"

.include "../../audio/liblastfm/buildlink3.mk"
BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.6nb1
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/taglib-extras/buildlink3.mk"
.include "../../databases/mysql51-embedded/buildlink3.mk"
.include "../../devel/qtscriptgenerator/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../multimedia/kdemultimedia4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
# for plasma
.include "../../x11/kdebase-workspace4/buildlink3.mk"
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs4>=4.3.0
.include "../../x11/kdelibs4/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.5.0
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
