# $NetBSD: Makefile,v 1.5 2000/09/28 20:34:04 fredb Exp $
#

DISTNAME=	xmysql-1.10
CATEGORIES=	databases x11
MASTER_SITES=	http://web.wt.net/~dblhack/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://web.wt.net/~dblhack

DEPENDS=	mysql-client-3.22.32:../../databases/mysql-client
DEPENDS+=	xforms>=0.88nb1:../../x11/xforms

USE_X11=	YES
USE_XPM=	YES

ALL_TARGET=	xmysql

.include "../../mk/bsd.pkg.mk"
