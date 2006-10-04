# $NetBSD: Makefile,v 1.8 2006/10/04 21:53:18 wiz Exp $

DISTNAME=	wmnet-1.2
PKGNAME=	wminet-1.2
PKGREVISION=	1
CATEGORIES=	net x11
MASTER_SITES=	ftp://ftp.enteract.com/users/rneswold/

MAINTAINER=	coto@core.de
HOMEPAGE=	http://users.rcn.com/rneswold/
COMMENT=	Dockable network monitor

NOT_FOR_PLATFORM=	Interix-*-* # no userland protocol stack support

USE_X11BASE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
