# $NetBSD: Makefile,v 1.1.1.1 2008/04/25 23:24:49 wiz Exp $
#

DISTNAME=	ggz-client-libs-0.0.14.1
CATEGORIES=	games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/ggzgamingzone/ggz/0.0.14.1/

MAINTAINER=	mrohrer@users.sourceforge.net
HOMEPAGE=	http://www.ggzgamingzone.org/
COMMENT=	GGZ Gaming Zone libraries

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.4
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-debug-gdb

.include "../../games/libggz/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
