# $NetBSD: Makefile,v 1.4 2000/08/23 23:14:22 tron Exp $
#

DISTNAME=	xmysqladmin-1.0
CATEGORIES=	databases x11
MASTER_SITES=	http://www.mysql.com/Contrib/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.mysql.com/

DEPENDS=	mysql-client-3.22.32:../../databases/mysql-client
DEPENDS+=	xforms-0.88:../../x11/xforms

USE_X11=	YES
USE_XPM=	YES

ALL_TARGET=	xmysqladmin

.include "../../mk/bsd.pkg.mk"
