# $NetBSD: Makefile,v 1.12 2002/12/28 21:22:54 jschauma Exp $
#

DISTNAME=	xmysqladmin-1.0
PKGREVISION=	2
CATEGORIES=	databases x11
MASTER_SITES=	http://gd.tuwien.ac.at/db/mysql/Downloads/Contrib/ \
		http://mysql-mirror.free.fr/Downloads/Contrib/ \
		http://www.fh-wolfenbuettel.de/ftp/pub/database/mysql/Downloads/Contrib/ \
		http://mysql.adgrafix.com/Downloads/Contrib/ \
		http://mysql.secsup.org/Downloads/Contrib/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.mysql.com/
COMMENT=	Graphical front end for administering MySQL databases

BUILDLINK_DEPENDS.mysql-client=	mysql-client>=3.23.35

USE_BUILDLINK2=	YES
USE_X11=	YES
MAKE_ENV+=	X11PREFIX=${X11PREFIX}

ALL_TARGET=	xmysqladmin

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xforms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
