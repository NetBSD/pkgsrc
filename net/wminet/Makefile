# $NetBSD: Makefile,v 1.6 2005/11/08 16:45:47 tv Exp $

DISTNAME=	wmnet-1.2
PKGNAME=	wminet-1.2
CATEGORIES=	net x11
MASTER_SITES=	ftp://ftp.enteract.com/users/rneswold/

MAINTAINER=	coto@core.de
HOMEPAGE=	http://www.enteract.com/~rneswold/
COMMENT=	Dockable network monitor

NOT_FOR_PLATFORM=	Interix-*-* # no userland protocol stack support

USE_X11BASE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
