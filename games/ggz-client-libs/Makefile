# $NetBSD: Makefile,v 1.11 2014/01/01 11:52:06 wiz Exp $
#

DISTNAME=	ggz-client-libs-0.0.14.1
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14.1/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://www.ggzgamingzone.org/
COMMENT=	GGZ Gaming Zone libraries

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt

CONFIGURE_ARGS+=	--enable-debug-gdb
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus ${PKG_SYSCONFDIR}/xdg/menus/applications-merged
CONF_FILES+=	${PREFIX}/share/examples/ggz-client-libs/ggz.menu \
		${PKG_SYSCONFDIR}/xdg/menus/ggz.menu
CONF_FILES+=	${PREFIX}/share/examples/ggz-client-libs/ggz.merge.menu \
		${PKG_SYSCONFDIR}/xdg/menus/ggz.merge.menu
CONF_FILES+=	/dev/null ${PKG_SYSCONFDIR}/ggz.modules

.include "../../games/libggz/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
