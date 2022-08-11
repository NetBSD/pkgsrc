# $NetBSD: Makefile,v 1.67 2022/08/11 05:08:11 gutteridge Exp $

DISTNAME=	ktexteditor-${KF5VER}
PKGREVISION=	3
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Advanced embeddable text editor
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	gmake msgmerge pkg-config perl

CMAKE_ARGS+=	-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/ktexteditor

LDFLAGS.SunOS+=	-mimpure-text

CONF_FILES+=	${PREFIX}/share/examples/ktexteditor/org.kde.ktexteditor.katetextbuffer.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.ktexteditor.katetextbuffer.conf

MAKE_DIRS+=		${PKG_SYSCONFDIR}/dbus-1/system.d
INSTALLATION_DIRS+=	share/examples/ktexteditor

.include "../../devel/editorconfig-core/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../textproc/syntax-highlighting/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
