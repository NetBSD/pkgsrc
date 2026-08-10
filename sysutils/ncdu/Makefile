# $NetBSD: Makefile,v 1.21 2026/08/10 08:55:56 adam Exp $

DISTNAME=	ncdu-1.22
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	https://dev.yorhel.nl/ncdu
COMMENT=	Disk usage visualization tool
LICENSE=	modified-bsd

USE_CURSES=	vw_printw
USE_TOOLS=	pkg-config
GNU_CONFIGURE=	yes
FAKE_NCURSES=	yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
