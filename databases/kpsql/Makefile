# $NetBSD: Makefile,v 1.5 2001/05/14 15:04:50 jlam Exp $
#

DISTNAME=	kpsql-1.0
CATEGORIES=	databases
MASTER_SITES=	http://www.mutinybaysoftware.com/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.mutinybaysoftware.com/kpsql.html
COMMENT=	Interactive Query Tool for PostgreSQL

DEPENDS+=	kdebase>=1.1:../../x11/kdebase
DEPENDS+=	postgresql-{6.5.3*,7.0*,lib-*}:../../databases/postgresql-lib

#
# PostgreSQL is currently not supported by all platforms
#
NOT_FOR_PLATFORM=       *-*-mips

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-qt-dir=${X11BASE}/qt1 \
		--with-pgsqldir=${LOCALBASE}

CONFIGURE_ENV+=	KDEDIR=${X11BASE} \
		MOC="${X11BASE}/qt1/bin/moc"

.include "../../mk/bsd.pkg.mk"
