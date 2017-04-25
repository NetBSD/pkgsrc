# $NetBSD: Makefile,v 1.7.2.1 2017/04/25 18:06:29 bsiegert Exp $

DISTNAME=	ncdu-1.12
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	https://dev.yorhel.nl/download/

COMMENT=	Disk usage visualization tool
MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://dev.yorhel.nl/ncdu
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
FAKE_NCURSES=	yes
USE_CURSES=	vw_printw

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
