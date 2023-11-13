# $NetBSD: Makefile,v 1.6 2023/11/13 23:09:24 gutteridge Exp $

DISTNAME=	lxmenu-data-0.1.5
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://lxde.org/
COMMENT=	LXDE menu data
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gettext gmake intltool msgfmt

MENU_CONF=		share/examples/menus
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/menus

CONF_FILES=	${MENU_CONF}/lxde-applications.menu \
		${PKG_SYSCONFDIR}/menus/lxde-applications.menu

.include "../../mk/bsd.pkg.mk"
