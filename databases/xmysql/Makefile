# $NetBSD: Makefile,v 1.9 2002/04/17 04:45:09 fredb Exp $
#

DISTNAME=	xmysql-1.10
PKGREVISION=	1
CATEGORIES=	databases x11
MASTER_SITES=	http://web.wt.net/~dblhack/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://web.wt.net/~dblhack
COMMENT=	Graphical front end to the MySQL database engine

DEPENDS+=	mysql-client>=3.23.35:../../databases/mysql-client
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	xforms>=0.9999:../../x11/xforms

MAKE_ENV+=	X11PREFIX=${X11PREFIX}
USE_X11=	YES
USE_XPM=	YES

ALL_TARGET=	xmysql

.include "../../mk/bsd.pkg.mk"
