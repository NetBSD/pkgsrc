# $NetBSD: Makefile,v 1.6 2000/11/03 20:56:31 veego Exp $
#

DISTNAME=	xmysqladmin-1.0
CATEGORIES=	databases x11
MASTER_SITES=	http://www.mysql.com/Contrib/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.mysql.com/

DEPENDS=	mysql-client-3.22.32:../../databases/mysql-client
DEPENDS+=	xforms>=0.88nb1:../../x11/xforms

MAKE_ENV+=	X11PREFIX=${X11PREFIX}

USE_X11=	YES
USE_XPM=	YES

ALL_TARGET=	xmysqladmin

.include "../../mk/bsd.pkg.mk"
