# $NetBSD: Makefile,v 1.10 2020/11/16 12:15:03 adam Exp $

PKGNAME=	${DISTNAME:S/-/11-contrib-/}
COMMENT=	Contrib subtree of tools and plug-ins

.include "../../databases/postgresql11/Makefile.common"

DEPENDS+=	postgresql11-server>=${PKGVERSION_NOREV}:../../databases/postgresql11-server

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS+=		contrib/adminpack
BUILD_DIRS+=		contrib/auth_delay
BUILD_DIRS+=		contrib/auto_explain
BUILD_DIRS+=		contrib/btree_gin
BUILD_DIRS+=		contrib/btree_gist
BUILD_DIRS+=		contrib/citext
BUILD_DIRS+=		contrib/cube
BUILD_DIRS+=		contrib/dblink
BUILD_DIRS+=		contrib/dict_int
BUILD_DIRS+=		contrib/dict_xsyn
BUILD_DIRS+=		contrib/earthdistance
BUILD_DIRS+=		contrib/file_fdw
BUILD_DIRS+=		contrib/fuzzystrmatch
BUILD_DIRS+=		contrib/hstore
BUILD_DIRS+=		contrib/intagg
BUILD_DIRS+=		contrib/intarray
BUILD_DIRS+=		contrib/isn
BUILD_DIRS+=		contrib/lo
BUILD_DIRS+=		contrib/ltree
BUILD_DIRS+=		contrib/oid2name
BUILD_DIRS+=		contrib/pageinspect
BUILD_DIRS+=		contrib/passwordcheck
BUILD_DIRS+=		contrib/pg_buffercache
BUILD_DIRS+=		contrib/pg_freespacemap
BUILD_DIRS+=		contrib/pg_prewarm
BUILD_DIRS+=		contrib/pg_standby
BUILD_DIRS+=		contrib/pg_stat_statements
BUILD_DIRS+=		contrib/pg_trgm
BUILD_DIRS+=		contrib/pgcrypto
BUILD_DIRS+=		contrib/pgrowlocks
BUILD_DIRS+=		contrib/pgstattuple
BUILD_DIRS+=		contrib/postgres_fdw
BUILD_DIRS+=		contrib/seg
BUILD_DIRS+=		contrib/spi
BUILD_DIRS+=		contrib/sslinfo
BUILD_DIRS+=		contrib/tablefunc
BUILD_DIRS+=		contrib/tcn
BUILD_DIRS+=		contrib/test_decoding
BUILD_DIRS+=		contrib/tsm_system_rows
BUILD_DIRS+=		contrib/tsm_system_time
BUILD_DIRS+=		contrib/unaccent
BUILD_DIRS+=		contrib/vacuumlo

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-openssl

PLIST_VARS+=		uuid
.if ${OPSYS:M*BSD} || ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PLIST.uuid=		yes
BUILD_DIRS+=		contrib/uuid-ossp
.  if ${OPSYS:M*BSD}
BUILD_MAKE_FLAGS+=	PG_CPPFLAGS="-DHAVE_UUID_H -DHAVE_UUID_BSD -DSHA1_RESULTLEN=20"
CONFIGURE_ARGS+=	--with-uuid=bsd
.  elif ${OPSYS} == "Linux"
BUILD_MAKE_FLAGS+=	PG_CPPFLAGS="-DHAVE_UUID_UUID_H -DHAVE_UUID_E2FS"
CONFIGURE_ARGS+=	--with-uuid=e2fs
.  elif ${OPSYS} == "SunOS"
BUILD_MAKE_FLAGS+=	PG_CPPFLAGS="-DHAVE_UUID_H -DHAVE_UUID_OSSP"
CONFIGURE_ARGS+=	--with-uuid=ossp
BUILD_MAKE_FLAGS+=	UUID_LIBS=-lossp-uuid
.  include "../../devel/ossp-uuid/buildlink3.mk"
.  endif
.endif

PRINT_PLIST_AWK+=	{if ($$0 ~ /uuid-ossp/) {$$0 = "$${PLIST.uuid}" $$0;}}

.include "../../databases/postgresql11-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
