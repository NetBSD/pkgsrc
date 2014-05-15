# $NetBSD: Makefile,v 1.9 2014/05/15 14:41:57 adam Exp $

DISTNAME=	kget-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	net
COMMENT=	download manager for KDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

REPLACE_PERL+= \
	conf/kget_limitdownloads.pl \
	conf/kget_sensitive.pl

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../misc/nepomuk-core/buildlink3.mk"
.include "../../misc/nepomuk-widgets/buildlink3.mk"
# libmms-0.6 has a broken header file. comment out till 0.6.2 in pkgsrc
##BUILDLINK_API_DEPENDS.libmms+=  libmms>=0.6.2
##.include "../../net/libmms/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
