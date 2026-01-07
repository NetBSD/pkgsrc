# $NetBSD: Makefile,v 1.54 2026/01/07 08:45:54 wiz Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	pavucontrol-qt-2.3.0
PKGREVISION=	2
CATEGORIES=	audio

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/pavucontrol-qt/
COMMENT=	Pulseaudio mixer implemented in Qt
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config perl

TOOL_DEPENDS+=	lxqt-build-tools>=2.3.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
