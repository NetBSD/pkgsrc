# $NetBSD: Makefile,v 1.2 1999/12/13 20:38:27 bad Exp $
#

DISTNAME=	xmysqladmin-1.0
CATEGORIES=	databases x11
MASTER_SITES=	http://www.mysql.com/Contrib/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.mysql.com/

DEPENDS=	mysql-client-3.22.27:../../databases/mysql-client
DEPENDS+=	xforms-0.88:../../x11/xforms
DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11=	yes

ALL_TARGET=	xmysqladmin

.include "../../mk/bsd.pkg.mk"
