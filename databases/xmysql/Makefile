# $NetBSD: Makefile,v 1.6 2000/11/03 20:53:47 veego Exp $
#

DISTNAME=	xmysql-1.10
CATEGORIES=	databases x11
MASTER_SITES=	http://web.wt.net/~dblhack/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://web.wt.net/~dblhack

DEPENDS=	mysql-client-3.22.32:../../databases/mysql-client
DEPENDS+=	xforms>=0.88nb1:../../x11/xforms

MAKE_ENV+=	X11PREFIX=${X11PREFIX}
USE_X11=	YES
USE_XPM=	YES

ALL_TARGET=	xmysql

.include "../../mk/bsd.pkg.mk"
