# $NetBSD: Makefile,v 1.2 2015/07/06 11:35:51 sborrill Exp $

DISTNAME=	ncdu-1.10
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ncdu/}

COMMENT=	Disk usage visualization tool
MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://dev.yorhel.nl/ncdu
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
INCOMPAT_CURSES=	NetBSD-[0-5]*-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
