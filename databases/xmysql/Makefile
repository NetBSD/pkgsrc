# $NetBSD: Makefile,v 1.22 2006/02/05 23:08:38 joerg Exp $
#

DISTNAME=	xmysql-1.10
PKGREVISION=	6
CATEGORIES=	databases x11
MASTER_SITES=	http://web.wt.net/~dblhack/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://web.wt.net/~dblhack
COMMENT=	Graphical front end to the MySQL database engine

MAKE_ENV+=	X11PREFIX=${X11PREFIX:Q}

BUILD_TARGET=	xmysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
