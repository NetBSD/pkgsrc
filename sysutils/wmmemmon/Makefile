# $NetBSD: Makefile,v 1.8 2007/01/23 16:17:23 joerg Exp $
#

DISTNAME=	wmmemmon-1.0.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/

MAINTAINER=	coto@core.de
HOMEPAGE=	http://www.sh.rim.or.jp/~ssato/dockapp/
COMMENT=	Dockapp to monitor memory and swap usages

GNU_CONFIGURE= 	YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
