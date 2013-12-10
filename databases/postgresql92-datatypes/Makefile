# $NetBSD: Makefile,v 1.5 2013/12/10 22:32:57 adam Exp $

PKGNAME=	${DISTNAME:C/-/92-datatypes-/}
COMMENT=	PostgreSQL data types support modules

DEPENDS+=	postgresql92-server>=${PKGVERSION_NOREV}:../../databases/postgresql92-server

.include "../../databases/postgresql92/Makefile.common"

PLIST_VARS+=		uuid

.if ${OPSYS} != "Darwin"
PLIST.uuid=		yes
CONFIGURE_ARGS+=	--with-ossp-uuid
# because global pg_config.h is included, we have to define this
CPPFLAGS+=		-DHAVE_UUID_H
BUILD_DIRS+=		contrib/uuid-ossp
.  include "../../devel/ossp-uuid/buildlink3.mk"
.endif

BUILD_DIRS+=		contrib/citext
BUILD_DIRS+=		contrib/hstore
BUILD_DIRS+=		contrib/intarray
BUILD_DIRS+=		contrib/isn
BUILD_DIRS+=		contrib/ltree
BUILD_DIRS+=		contrib/lo
BUILD_DIRS+=		contrib/unaccent
BUILD_MAKE_FLAGS=	PGXS=1

.include "../../databases/postgresql92-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
