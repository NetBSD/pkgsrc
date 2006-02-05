# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:32 joerg Exp $

DISTNAME=	wmnet-1.2
PKGNAME=	wminet-1.2
PKGREVISION=	1
CATEGORIES=	net x11
MASTER_SITES=	ftp://ftp.enteract.com/users/rneswold/

MAINTAINER=	coto@core.de
HOMEPAGE=	http://www.enteract.com/~rneswold/
COMMENT=	Dockable network monitor

NOT_FOR_PLATFORM=	Interix-*-* # no userland protocol stack support

USE_X11BASE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
