# $NetBSD: Makefile,v 1.4 2016/03/05 11:28:16 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/94-datatypes-/}
PKGREVISION=	1
COMMENT=	PostgreSQL data types support modules

DEPENDS+=	postgresql94-server>=${PKGVERSION_NOREV}:../../databases/postgresql94-server

.include "../../databases/postgresql94/Makefile.common"

PLIST_VARS+=		uuid

.if ${OPSYS} != "Darwin"
PLIST.uuid=		yes
CONFIGURE_ARGS+=	--with-ossp-uuid
BUILD_DIRS+=		contrib/uuid-ossp
.include "../../devel/ossp-uuid/buildlink3.mk"

MAKE_FLAGS+=	UUID_LIBS=-lossp-uuid
.endif

BUILD_DIRS+=		contrib/btree_gist
BUILD_DIRS+=		contrib/citext
BUILD_DIRS+=		contrib/hstore
BUILD_DIRS+=		contrib/intarray
BUILD_DIRS+=		contrib/isn
BUILD_DIRS+=		contrib/ltree
BUILD_DIRS+=		contrib/lo
BUILD_DIRS+=		contrib/unaccent
BUILD_MAKE_FLAGS=	USE_PGXS=1

.include "../../databases/postgresql94-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
