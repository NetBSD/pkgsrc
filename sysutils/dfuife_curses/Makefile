# $NetBSD: Makefile,v 1.2 2006/05/18 20:30:01 wiz Exp $
#

DISTNAME=	dfuife_curses-1.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://packages.stura.uni-rostock.de/bsdinstaller/distfiles/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	DFUI curses frontend

BROKEN_IN=	pkgsrc-2006Q1

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
