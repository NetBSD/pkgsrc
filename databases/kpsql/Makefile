# $NetBSD: Makefile,v 1.2 2000/12/27 00:18:09 wulf Exp $
#

DISTNAME=	kpsql-1.0
CATEGORIES=	databases
MASTER_SITES=	http://www.mutinybaysoftware.com/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.mutinybaysoftware.com/kpsql.html

DEPENDS+=	kdebase>=1.1:../../x11/kdebase
DEPENDS+=	postgresql>=6.4:../../databases/postgresql

#
# PostgreSQL is currently not supported by all platforms
#
NOT_FOR_PLATFORM=       *-*-alpha *-*-mips

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-qt-dir=${X11BASE}/qt1 \
		--with-pgsqldir=${LOCALBASE}

CONFIGURE_ENV+=	KDEDIR=${X11BASE} \
		MOC="${X11BASE}/qt1/bin/moc"

.include "../../mk/bsd.pkg.mk"
