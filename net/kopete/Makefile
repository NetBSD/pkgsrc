# $NetBSD: Makefile,v 1.45 2019/07/01 04:08:41 ryoon Exp $

DISTNAME=	kopete-16.12.0
PKGREVISION=	16
CATEGORIES=	net
COMMENT=	Multi-protocol instant messenger client
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.12.0/src/}

# Race on translatorplugin.h
MAKE_JOBS_SAFE=	no

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_LANGUAGES+=	c++11

CMAKE_ARGS+=	-DWITH_Xmms:BOOL=OFF

REPLACE_PERL+= \
	kopete/kconf_update/kopete-account-0.10.pl \
	kopete/kconf_update/kopete-gaim_to_pidgin_style.pl \
	kopete/kconf_update/kopete-initialstatus.pl \
	kopete/kconf_update/kopete-pluginloader.pl \
	kopete/kconf_update/kopete-update_icq_server.pl \
	kopete/kconf_update/kopete-update_icq_ssl.pl \
	kopete/kconf_update/kopete-update_yahoo_server.pl

REPLACE_SH+= \
	protocols/winpopup/winpopup-install \
	protocols/winpopup/winpopup-send

# jasper uses SIZE_MAX and friends in its headers.
CXXFLAGS+=	-D__STDC_LIMIT_MACROS

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/alsa-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmsn+=  libmsn>=4.1
.include "../../chat/libmsn/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../chat/meanwhile/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../net/ortp/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
