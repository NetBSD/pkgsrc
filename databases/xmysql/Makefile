# $NetBSD: Makefile,v 1.14 2004/04/25 17:49:55 snj Exp $
#

DISTNAME=	xmysql-1.10
PKGREVISION=	3
CATEGORIES=	databases x11
MASTER_SITES=	http://web.wt.net/~dblhack/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://web.wt.net/~dblhack
COMMENT=	Graphical front end to the MySQL database engine

BUILDLINK_DEPENDS.mysql-client=	mysql-client>=3.23.35

USE_BUILDLINK3=	YES
USE_X11=	YES
MAKE_ENV+=	X11PREFIX=${X11PREFIX}

ALL_TARGET=	xmysql

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
