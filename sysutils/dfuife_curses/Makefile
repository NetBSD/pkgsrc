# $NetBSD: Makefile,v 1.4 2007/07/16 21:38:38 joerg Exp $
#

DISTNAME=	dfuife_curses-1.5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pkgsrc-box.org/bsdinstaller/distfiles/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	DFUI curses frontend

USE_LIBTOOL=	yes
USE_NCURSES=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	msgfmt

MAKE_ENV+=	LOCALEDIR=${PREFIX:Q}/${PKGLOCALEDIR:Q}/locale

.include "../../devel/libaura/buildlink3.mk"
.include "../../devel/libdfui/buildlink3.mk"
.include "../../devel/libinstaller/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
