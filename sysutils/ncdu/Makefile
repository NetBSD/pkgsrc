# $NetBSD: Makefile,v 1.18 2023/02/28 21:10:28 nikita Exp $

DISTNAME=	ncdu-1.18.1
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	https://dev.yorhel.nl/ncdu
COMMENT=	Disk usage visualization tool
LICENSE=	modified-bsd

CONFLICTS+=	ncdu-2.*

GNU_CONFIGURE=	yes
FAKE_NCURSES=	yes
USE_CURSES=	vw_printw

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
