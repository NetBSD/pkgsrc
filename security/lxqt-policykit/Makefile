# $NetBSD: Makefile,v 1.45 2026/04/28 08:13:37 pin Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-policykit-2.4.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-policykit/
COMMENT=	Policykit authentication agent
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl

AUTOSTART_CONF=		share/examples/autostart
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/autostart

CONF_FILES+=	${AUTOSTART_CONF}/lxqt-policykit-agent.desktop \
		${PKG_SYSCONFDIR}/autostart/lxqt-policykit-agent.desktop

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/liblxqt/buildlink3.mk"
.include "../../security/polkit-qt6/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
