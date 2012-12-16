# $NetBSD: Makefile,v 1.8 2012/12/16 01:52:04 obache Exp $

PKGNAME=	${DISTNAME:C/-/90-datatypes-/}
PKGREVISION=	1
COMMENT=	PostgreSQL data types support modules

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

CONFIGURE_ARGS+=	--with-ossp-uuid
BUILD_MAKE_FLAGS=	PGXS=1
# because global pg_config.h is included, we have to define this
CPPFLAGS+=		-DHAVE_UUID_H

BUILD_DIRS+=		contrib/citext
BUILD_DIRS+=		contrib/hstore
BUILD_DIRS+=		contrib/intarray
BUILD_DIRS+=		contrib/isn
BUILD_DIRS+=		contrib/ltree
BUILD_DIRS+=		contrib/lo
BUILD_DIRS+=		contrib/uuid-ossp
BUILD_DIRS+=		contrib/unaccent
REQD_DIRS+=		${PG_SUBPREFIX}lib/postgresql
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../devel/ossp-uuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
