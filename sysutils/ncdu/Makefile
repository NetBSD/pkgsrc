# $NetBSD: Makefile,v 1.3 2015/08/17 17:11:29 wiz Exp $

DISTNAME=	ncdu-1.10
PKGREVISION=	1
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
