# $NetBSD: Makefile,v 1.8 2001/03/26 14:54:20 bad Exp $
#

DISTNAME=	xmysqladmin-1.0
CATEGORIES=	databases x11
MASTER_SITES=	http://www.mysql.com/Contrib/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.mysql.com/
COMMENT=	Graphical front end for administering MySQL databases

DEPENDS=	mysql-client>=3.23.35:../../databases/mysql-client
DEPENDS+=	xforms>=0.88nb1:../../x11/xforms

MAKE_ENV+=	X11PREFIX=${X11PREFIX}

USE_X11=	YES
USE_XPM=	YES

ALL_TARGET=	xmysqladmin

.include "../../mk/bsd.pkg.mk"
