# $NetBSD: Makefile,v 1.17 2004/12/03 15:14:53 wiz Exp $
#

DISTNAME=	xmysql-1.10
PKGREVISION=	4
CATEGORIES=	databases x11
MASTER_SITES=	http://web.wt.net/~dblhack/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://web.wt.net/~dblhack
COMMENT=	Graphical front end to the MySQL database engine

BUILDLINK_DEPENDS.mysql-client=	mysql-client>=3.23.35

USE_BUILDLINK3=	YES
USE_X11=	YES
MAKE_ENV+=	X11PREFIX=${X11PREFIX}

BUILD_TARGET=	xmysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
