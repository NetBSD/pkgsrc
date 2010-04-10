# $NetBSD: Makefile,v 1.14 2010/04/10 00:07:07 markd Exp $

DISTNAME=	akonadi-1.3.1
CATEGORIES=	mail
MASTER_SITES=	http://download.akonadi-project.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://pim.kde.org/akonadi/
COMMENT=	The KDE PIM Storage Service
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	mysql-server-[0-9]*:../../databases/mysql5-server
DEPENDS+=	qt4-mysql-[0-9]*:../../x11/qt4-mysql

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

PKGCONFIG_OVERRIDE+=	akonadi.pc.cmake

SUBST_CLASSES+=		mysql
SUBST_STAGE.mysql=	post-patch
SUBST_MESSAGE.mysql=	Fix mysqld path.
SUBST_FILES.mysql=	server/CMakeLists.txt
SUBST_SED.mysql=	-e "s:MYSQLD_EXECUTABLE mysqld:MYSQLD_EXECUTABLE mysqld ${PREFIX}/libexec:"

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/soprano/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
