# $NetBSD: Makefile,v 1.19 2026/01/07 08:47:54 wiz Exp $

DISTNAME=	akonadi-contacts-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Libraries and daemons to implement basic email handling
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/*/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../graphics/kf6-prison/buildlink3.mk"
.include "../../mail/akonadi/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../misc/grantleetheme/buildlink3.mk"
.include "../../misc/kf6-kcontacts/buildlink3.mk"
.include "../../textproc/ktextaddons/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
