# $NetBSD: Makefile,v 1.9.2.1 2002/06/23 18:43:37 jlam Exp $
#

DISTNAME=	xmysqladmin-1.0
PKGREVISION=	1
CATEGORIES=	databases x11
MASTER_SITES=	http://gd.tuwien.ac.at/db/mysql/Downloads/Contrib/ \
		http://mysql-mirror.free.fr/Downloads/Contrib/ \
		http://www.fh-wolfenbuettel.de/ftp/pub/database/mysql/Downloads/Contrib/ \
		http://mysql.adgrafix.com/Downloads/Contrib/ \
		http://mysql.secsup.org/Downloads/Contrib/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.mysql.com/
COMMENT=	Graphical front end for administering MySQL databases

DEPENDS=	mysql-client>=3.23.35:../../databases/mysql-client
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	xforms>=0.9999:../../x11/xforms

MAKE_ENV+=	X11PREFIX=${X11PREFIX}

USE_X11=	YES
USE_XPM=	YES

ALL_TARGET=	xmysqladmin

.include "../../mk/bsd.pkg.mk"
