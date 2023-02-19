# $NetBSD: Makefile,v 1.17 2023/02/19 19:51:29 wiz Exp $

DISTNAME=	ncdu-1.18.1
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	https://dev.yorhel.nl/ncdu
COMMENT=	Disk usage visualization tool
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
FAKE_NCURSES=	yes
USE_CURSES=	vw_printw

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
