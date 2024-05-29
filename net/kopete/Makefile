# $NetBSD: Makefile,v 1.80 2024/05/29 16:33:56 adam Exp $

DISTNAME=	kopete-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	net

HOMEPAGE=	https://kde.org/applications/internet/kopete/
COMMENT=	Multi-protocol instant messenger client
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/*/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	kopete/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kopeterc \
		${PKG_SYSCONFDIR}/xdg/kopeterc

REPLACE_PERL+= \
	kopete/kconf_update/kopete-account-0.10.pl \
	kopete/kconf_update/kopete-gaim_to_pidgin_style.pl \
	kopete/kconf_update/kopete-initialstatus.pl \
	kopete/kconf_update/kopete-pluginloader.pl \
	kopete/kconf_update/kopete-update_icq_server.pl \
	kopete/kconf_update/kopete-update_icq_ssl.pl

REPLACE_SH+= \
	protocols/winpopup/winpopup-install \
	protocols/winpopup/winpopup-send

.include "../../chat/libgadu/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
#.include "../../chat/meanwhile/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kcontacts/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../net/ortp/buildlink3.mk"
.include "../../security/libkleo/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
