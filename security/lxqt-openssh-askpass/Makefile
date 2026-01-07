# $NetBSD: Makefile,v 1.45 2026/01/07 08:48:42 wiz Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-openssh-askpass-2.3.0
PKGREVISION=	2
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-openssh-askpass/
COMMENT=	Tool used with openssh to prompt the user for a password
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl

TOOL_DEPENDS+=	lxqt-build-tools>=2.3.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
