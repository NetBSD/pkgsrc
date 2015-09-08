# $NetBSD: Makefile,v 1.5 2015/09/08 11:57:50 jperkin Exp $

DISTNAME=	ncdu-1.10
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ncdu/}

COMMENT=	Disk usage visualization tool
MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://dev.yorhel.nl/ncdu
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
INCOMPAT_CURSES=	NetBSD-[0-5].*-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
