# $NetBSD: Makefile,v 1.1 2024/05/26 12:09:29 markd Exp $

DISTNAME=	ktexteditor-${KF6VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Advanced embeddable text editor
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	gmake msgmerge pkg-config perl

CMAKE_ARGS+=	-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/kf6-ktexteditor

LDFLAGS.SunOS+=	-mimpure-text

CONF_FILES+=	${PREFIX}/share/examples/kf6-ktexteditor/org.kde.ktexteditor6.katetextbuffer.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.ktexteditor6.katetextbuffer.conf

MAKE_DIRS+=		${PKG_SYSCONFDIR}/dbus-1/system.d
INSTALLATION_DIRS+=	share/examples/kf6-ktexteditor

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/editorconfig-core/buildlink3.mk"
#.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../security/kf6-kauth/buildlink3.mk"
.include "../../textproc/kf6-sonnet/buildlink3.mk"
.include "../../textproc/kf6-syntax-highlighting/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
