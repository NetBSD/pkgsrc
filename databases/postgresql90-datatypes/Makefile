# $NetBSD: Makefile,v 1.1.1.1 2010/12/11 23:01:51 asau Exp $

PKGNAME=	postgresql90-datatypes-${BASE_VERS}
COMMENT=	PostgreSQL data types support modules

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql90-server>=${BASE_VERS}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

CONFIGURE_ARGS+=	--with-ossp-uuid

BUILD_DIRS+=		contrib/citext
BUILD_DIRS+=		contrib/hstore
BUILD_DIRS+=		contrib/intarray
BUILD_DIRS+=		contrib/isn
BUILD_DIRS+=		contrib/ltree
BUILD_DIRS+=		contrib/lo
BUILD_DIRS+=		contrib/uuid-ossp
BUILD_DIRS+=		contrib/unaccent

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

REQD_DIRS+=		${PG_SUBPREFIX}lib/postgresql
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql90-client/buildlink3.mk"

.include "../../devel/ossp-uuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
