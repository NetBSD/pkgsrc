# $NetBSD: Makefile,v 1.19 2009/04/25 11:25:42 tnn Exp $
#

DISTNAME=	mined-2000.15
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	Html-aware editor

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FILE=	makefile
USE_TOOLS+=	gmake

post-install:
		${CHMOD} -x ${DESTDIR}${PREFIX}/share/mined/conf_user/xinitrc.mined

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
