# $NetBSD: Makefile,v 1.1.1.1 1999/08/05 17:20:11 bad Exp $
#

DISTNAME=	xmysqladmin-1.0
CATEGORIES=	databases x11
MASTER_SITES=	http://www.mysql.com/Contrib/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.mysql.com/

DEPENDS=	mysql-client-3.22.22:../../databases/mysql-client
DEPENDS+=	xforms-0.88:../../x11/xforms
DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11=	yes

ALL_TARGET=	xmysqladmin

.include "../../mk/bsd.pkg.mk"
