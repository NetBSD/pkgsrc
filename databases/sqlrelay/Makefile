# $NetBSD: Makefile,v 1.5 2004/10/03 00:13:23 tv Exp $

DISTNAME=		sqlrelay-0.33.1
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlrelay/}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://sqlrelay.sourceforge.net/
COMMENT=		Enables pooling and sharing of database connections

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GCC_SHLIB=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

#SQLRELAY_DATABASES+=	mysql postgresql
SQLRELAY_DATABASES?=	# empty

.for _db_ in ${SQLRELAY_DATABASES}
SQLRELAY.${_db_}?=	YES
.endfor

.if defined(SQLRELAY.mysql) && ${SQLRELAY.mysql} == "YES"
.  include "../../databases/mysql-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_DIR}
.endif

.if defined(SQLRELAY.postgresql) && ${SQLRELAY.postgresql} == "YES"
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgresql=${BUILDLINK_DIR}
.endif

.include "../../devel/rudiments/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
