# $NetBSD: Makefile,v 1.12 2014/02/12 23:17:39 tron Exp $

PKGNAME=	${DISTNAME:S/-/-server-/}
PKGREVISION=	1
SVR4_PKGNAME=	mysqs
COMMENT=	MySQL 5, a free SQL database (server)

CONFLICTS=	mysql3-server-[0-9]*

.include "../../databases/mysql56-client/Makefile.common"

CMAKE_ARGS+=		-DWITH_LIBWRAP=ON
CMAKE_ARGS+=		-DINSTALL_INFODIR=${PKGINFODIR}

.if !empty(PKG_OPTIONS:Membedded-server)
CMAKE_ARGS+=		-DWITH_EMBEDDED_SERVER=ON
PLIST.embedded=		yes
.else
CMAKE_ARGS+=		-DWITH_EMBEDDED_SERVER=OFF
# We only need readline to placate the configure script if we don't build
# the embedded server as it is the only binary linked against "readline".
BUILDLINK_DEPMETHOD.readline=	build
.endif

# ndb-cluster does not configure with cmake
#.if !empty(PKG_OPTIONS:Mndb-cluster)
#CMAKE_ARGS+=		-DWITH_NDBCLUSTER_STORAGE_ENGINE=ON
#REPLACE_PERL+=		storage/ndb/tools/ndb_error_reporter
#REPLACE_PERL+=		storage/ndb/tools/ndb_size.pl
#PLIST.ndb=		yes
#.endif

PLIST_VARS+=		embedded ndb auth_socket

.if ${OPSYS} == "Linux"
PLIST.auth_socket=	yes
.endif

PTHREAD_OPTS+=		require

PKG_GROUPS=		${MYSQL_GROUP}
PKG_USERS=		${MYSQL_USER}:${MYSQL_GROUP}

PKG_GECOS.${MYSQL_USER}=	MySQL database administrator
PKG_HOME.${MYSQL_USER}=		${MYSQL_DATADIR}
PKG_SHELL.${MYSQL_USER}=	${SH}

RCD_SCRIPTS=		mysqld

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}
FILES_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
FILES_SUBST+=		MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
MESSAGE_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
MESSAGE_SUBST+=		MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
BUILD_DEFS+=		MYSQL_DATADIR

REPLACE_PERL+=		sql-bench/*.sh
REPLACE_PERL+=		mysql-test/lib/v1/mysql-test-run.pl
REPLACE_PERL+=		mysql-test/mysql-stress-test.pl
REPLACE_PERL+=		mysql-test/mysql-test-run.pl
REPLACE_PERL+=		mysql-test/std_data/checkDBI_DBD-mysql.pl
REPLACE_PERL+=		mysql-test/suite/engines/rr_trx/run_stress_tx_rr.pl
REPLACE_PERL+=		mysql-test/suite/funcs_1/lib/DataGen_local.pl
REPLACE_PERL+=		mysql-test/suite/funcs_1/lib/DataGen_modify.pl
REPLACE_PERL+=		mysql-test/suite/funcs_2/lib/gen_charset_utf8.pl
REPLACE_PERL+=		mysql-test/suite/rpl/extension/bhs.pl
REPLACE_PERL+=		mysql-test/suite/rpl/extension/checksum.pl

# Replace interpreter without pulling in Python dependecy
# Update when PYTHON_VERSION_DEFAULT changes!
SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fixing Python path.
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python+=	mysql-test/suite/opt_trace/validate_json.py
SUBST_SED.python+=	-e 's,/usr/bin/python,${PREFIX}/bin/python2.7,'

INSTALLATION_DIRS=	bin

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=		-D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__
CXXFLAGS+=		-D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__
.endif

BUILDLINK_AUTO_DIRS.mysql-client=	no
.include "../../databases/mysql56-client/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
