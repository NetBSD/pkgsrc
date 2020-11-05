# $NetBSD: Makefile,v 1.52 2020/11/05 09:08:53 ryoon Exp $

DISTNAME=	kget-15.12.0
PKGREVISION=	32
CATEGORIES=	net
COMMENT=	download manager for KDE
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

CMAKE_ARGS+=	-DWITH_NepomukCore:BOOL=OFF
CMAKE_ARGS+=	-DWITH_NepomukWidgets:BOOL=OFF
CMAKE_ARGS+=	-DWITH_KTorrent:BOOL=OFF

REPLACE_PERL+= \
	conf/kget_limitdownloads.pl \
	conf/kget_sensitive.pl

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
# libmms-0.6 has a broken header file. comment out till 0.6.2 in pkgsrc
##BUILDLINK_API_DEPENDS.libmms+=  libmms>=0.6.2
##.include "../../net/libmms/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
