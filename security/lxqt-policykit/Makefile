# $NetBSD: Makefile,v 1.27 2023/11/12 13:23:25 wiz Exp $

DISTNAME=	lxqt-policykit-1.3.0
PKGREVISION=	5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-policykit/
COMMENT=	Policykit authentication agent
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

AUTOSTART_CONF=		share/examples/autostart
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/autostart

CONF_FILES+=	${AUTOSTART_CONF}/lxqt-policykit-agent.desktop \
		${PKG_SYSCONFDIR}/autostart/lxqt-policykit-agent.desktop

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools>=0.13.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/liblxqt/buildlink3.mk"
.include "../../security/polkit-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
