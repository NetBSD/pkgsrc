# $NetBSD: Makefile,v 1.10 2003/07/13 17:59:17 wiz Exp $
#

DISTNAME=	kpsql-1.0
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://www.mutinybaysoftware.com/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.mutinybaysoftware.com/kpsql.html
COMMENT=	Interactive Query Tool for PostgreSQL

DEPENDS+=	kdebase-1.1.2nb3:../../x11/kdebase
DEPENDS+=	postgresql-lib>=7.3.1:../../databases/postgresql-lib

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-qt-dir=${X11BASE}/qt1 \
		--with-pgsqldir=${LOCALBASE}

CONFIGURE_ENV+=	KDEDIR=${X11BASE} \
		MOC="${X11BASE}/qt1/bin/moc"

.include "../../mk/bsd.pkg.mk"
