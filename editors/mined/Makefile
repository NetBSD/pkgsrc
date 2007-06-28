# $NetBSD: Makefile,v 1.17 2007/06/28 19:44:09 joerg Exp $
#

DISTNAME=	mined-2000.13.2
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://towo.net/mined/
COMMENT=	Html-aware editor

MAKE_FILE=	makefile
USE_TOOLS+=	gmake

post-install:
		${CHMOD} -x ${PREFIX}/share/mined/conf_user/xinitrc.mined

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
