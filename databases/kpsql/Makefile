# $NetBSD: Makefile,v 1.12 2003/11/14 10:02:15 wiz Exp $
#

DISTNAME=	kpsql-1.0
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.mutinybaysoftware.com/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.mutinybaysoftware.com/kpsql.html
COMMENT=	Interactive Query Tool for PostgreSQL

USE_BUILDLINK2=	yes
USE_X11=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-qt-dir=${QTDIR} \
		--with-pgsqldir=${BUILDLINK_PREFIX.postgresql-lib}

CONFIGURE_ENV+=	KDEDIR=${BUILDLINK_PREFIX.kdebase}

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../x11/kdebase/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
