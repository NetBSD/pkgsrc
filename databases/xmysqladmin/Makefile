# $NetBSD: Makefile,v 1.22 2006/01/08 18:35:09 xtraeme Exp $
#

DISTNAME=	xmysqladmin-1.0
PKGREVISION=	5
CATEGORIES=	databases x11
MASTER_SITES=	http://gd.tuwien.ac.at/db/mysql/Downloads/Contrib/ \
		http://mysql-mirror.free.fr/Downloads/Contrib/ \
		http://www.fh-wolfenbuettel.de/ftp/pub/database/mysql/Downloads/Contrib/ \
		http://mysql.adgrafix.com/Downloads/Contrib/ \
		http://mysql.secsup.org/Downloads/Contrib/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.mysql.com/
COMMENT=	Graphical front end for administering MySQL databases

MAKE_ENV+=	X11PREFIX=${X11PREFIX:Q}

BUILD_TARGET=	xmysqladmin

.include "../../mk/mysql.buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
