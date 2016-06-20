# $NetBSD: Makefile,v 1.3 2016/06/20 05:54:55 wiz Exp $

DISTNAME=	kcoreaddons-${KF5VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtCore
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND modified-bsd

.include "../../meta-pkgs/kf5/Makefile.common"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
# Work-around bad use-warning check in GNU ld 2.26
# /usr/lib/librpcsvc.so.1: warning: warning: this program uses xdr_peername(), which is deprecated and buggy.
# is triggered, even though the current linker output contains
# no references to it.
BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings
.endif

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
