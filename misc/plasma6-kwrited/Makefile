# $NetBSD: Makefile,v 1.4 2026/02/06 10:05:23 wiz Exp $

DISTNAME=	kwrited-${PLASMAVER}
PKGREVISION=	3
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	KDE daemon listening for wall and write messages
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_AUTOSTARTDIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

PLIST_VARS+=		utempter noutempter
.if ${OPSYS} == "Linux" && exists(/usr/include/utempter.h)
PLIST.utempter=		yes
.elif ${OPSYS} == "FreeBSD" && exists(/usr/include/utempter.h)
PLIST.utempter=		yes
.else
PLIST.noutempter=	yes
CONF_FILES+=		${PREFIX}/share/examples/kde-xdg/autostart/kwrited-autostart.desktop \
			${PKG_SYSCONFDIR}/xdg/autostart/kwrited-autostart.desktop
.endif

.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-kpty/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
