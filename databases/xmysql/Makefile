# $NetBSD: Makefile,v 1.10 2002/09/21 00:33:54 jlam Exp $
#

DISTNAME=	xmysql-1.10
PKGREVISION=	1
CATEGORIES=	databases x11
MASTER_SITES=	http://web.wt.net/~dblhack/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://web.wt.net/~dblhack
COMMENT=	Graphical front end to the MySQL database engine

BUILDLINK_DEPENDS.mysql-client=	mysql-client>=3.23.35

USE_BUILDLINK2=	YES
USE_X11=	YES
MAKE_ENV+=	X11PREFIX=${X11PREFIX}

ALL_TARGET=	xmysql

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xforms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
