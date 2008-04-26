# $NetBSD: Makefile,v 1.2 2008/04/26 13:38:15 markd Exp $
#

DISTNAME=	ggz-client-libs-0.0.14.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14.1/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://www.ggzgamingzone.org/
COMMENT=	GGZ Gaming Zone libraries

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.4
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-debug-gdb
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus ${PKG_SYSCONFDIR}/xdg/menus/applications-merged
CONF_FILES+=	${PREFIX}/share/examples/ggz-client-libs/ggz.menu \
		${PKG_SYSCONFDIR}/xdg/menus/ggz.menu
CONF_FILES+=	${PREFIX}/share/examples/ggz-client-libs/ggz.merge.menu \
		${PKG_SYSCONFDIR}/xdg/menus/ggz.merge.menu

.include "../../games/libggz/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
