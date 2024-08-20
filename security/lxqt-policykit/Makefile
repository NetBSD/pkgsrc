# $NetBSD: Makefile,v 1.32 2024/08/20 06:13:57 pin Exp $

DISTNAME=	lxqt-policykit-2.0.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-policykit/
COMMENT=	Policykit authentication agent
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

AUTOSTART_CONF=		share/examples/autostart
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/autostart

CONF_FILES+=	${AUTOSTART_CONF}/lxqt-policykit-agent.desktop \
		${PKG_SYSCONFDIR}/autostart/lxqt-policykit-agent.desktop

TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/liblxqt/buildlink3.mk"
.include "../../security/polkit-qt6/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
