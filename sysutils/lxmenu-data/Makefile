# $NetBSD: Makefile,v 1.3 2017/08/07 08:54:16 jlam Exp $

DISTNAME=	lxmenu-data-0.1.5
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://lxde.sourceforge.net/
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
