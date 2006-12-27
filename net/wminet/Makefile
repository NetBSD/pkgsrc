# $NetBSD: Makefile,v 1.10 2006/12/27 13:37:39 joerg Exp $

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

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
