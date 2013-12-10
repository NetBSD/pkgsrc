# $NetBSD: Makefile,v 1.11 2013/12/10 22:32:56 adam Exp $

PKGNAME=	${DISTNAME:C/-/90-datatypes-/}
COMMENT=	PostgreSQL data types support modules

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

PLIST_VARS+=		uuid

.if ${OPSYS} != "Darwin"
PLIST.uuid=		yes
CONFIGURE_ARGS+=	--with-ossp-uuid
# because global pg_config.h is included, we have to define this
CPPFLAGS+=		-DHAVE_UUID_H
BUILD_DIRS+=		contrib/uuid-ossp
.  include "../../devel/ossp-uuid/buildlink3.mk"
.endif

BUILD_MAKE_FLAGS=	PGXS=1
BUILD_DIRS+=		contrib/citext
BUILD_DIRS+=		contrib/hstore
BUILD_DIRS+=		contrib/intarray
BUILD_DIRS+=		contrib/isn
BUILD_DIRS+=		contrib/ltree
BUILD_DIRS+=		contrib/lo
BUILD_DIRS+=		contrib/unaccent
REQD_DIRS+=		lib/postgresql
REQD_DIRS+=		share/postgresql/contrib

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
