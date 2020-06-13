# $NetBSD: Makefile,v 1.13 2020/06/13 10:03:04 fcambus Exp $

DISTNAME=	ncdu-1.15.1
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
