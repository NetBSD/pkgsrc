# $NetBSD: Makefile,v 1.1.1.1 1999/08/05 17:21:39 bad Exp $
#

DISTNAME=	xmysql-1.10
CATEGORIES=	databases x11
MASTER_SITES=	http://web.wt.net/~dblhack/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://web.wt.net/~dblhack

DEPENDS=	mysql-client-3.22.22:../../databases/mysql-client
DEPENDS+=	xforms-0.88:../../x11/xforms
DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11=	yes

ALL_TARGET=	xmysql

.include "../../mk/bsd.pkg.mk"
