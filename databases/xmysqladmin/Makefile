# $NetBSD: Makefile,v 1.15 2004/04/25 17:48:44 snj Exp $
#

DISTNAME=	xmysqladmin-1.0
PKGREVISION=	3
CATEGORIES=	databases x11
MASTER_SITES=	http://gd.tuwien.ac.at/db/mysql/Downloads/Contrib/ \
		http://mysql-mirror.free.fr/Downloads/Contrib/ \
		http://www.fh-wolfenbuettel.de/ftp/pub/database/mysql/Downloads/Contrib/ \
		http://mysql.adgrafix.com/Downloads/Contrib/ \
		http://mysql.secsup.org/Downloads/Contrib/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.mysql.com/
COMMENT=	Graphical front end for administering MySQL databases

BUILDLINK_DEPENDS.mysql-client=	mysql-client>=3.23.35

USE_BUILDLINK3=	YES
USE_X11=	YES
MAKE_ENV+=	X11PREFIX=${X11PREFIX}

ALL_TARGET=	xmysqladmin

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
