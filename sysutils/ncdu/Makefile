# $NetBSD: Makefile,v 1.16 2023/01/03 13:29:49 wiz Exp $

DISTNAME=	ncdu-1.18
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
