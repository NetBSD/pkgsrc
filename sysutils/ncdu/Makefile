# $NetBSD: Makefile,v 1.6 2016/12/04 22:59:56 wiedi Exp $

DISTNAME=	ncdu-1.12
CATEGORIES=	filesystems
MASTER_SITES=	https://dev.yorhel.nl/download/

COMMENT=	Disk usage visualization tool
MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://dev.yorhel.nl/ncdu
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
INCOMPAT_CURSES=	NetBSD-[0-5].*-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
