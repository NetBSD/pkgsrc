# $NetBSD: Makefile,v 1.23 2006/10/04 20:53:46 wiz Exp $
#

DISTNAME=	xmysql-1.10
PKGREVISION=	6
CATEGORIES=	databases x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	# AWOL since 2002
COMMENT=	Graphical front end to the MySQL database engine

MAKE_ENV+=	X11PREFIX=${X11PREFIX:Q}

BUILD_TARGET=	xmysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
