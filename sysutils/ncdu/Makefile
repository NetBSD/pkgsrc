# $NetBSD: Makefile,v 1.14 2021/07/05 20:37:11 fcambus Exp $

DISTNAME=	ncdu-1.16
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

COMMENT=	Disk usage visualization tool
MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	https://dev.yorhel.nl/ncdu
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
FAKE_NCURSES=	yes
USE_CURSES=	vw_printw

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
