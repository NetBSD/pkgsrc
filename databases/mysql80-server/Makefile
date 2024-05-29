# $NetBSD: Makefile,v 1.22 2024/05/29 16:31:44 adam Exp $

PKGNAME=	${DISTNAME:S/-/-server-/}
PKGREVISION=	3
COMMENT=	MySQL 8, a free SQL database (server)

CONFLICTS=	mysql3-server-[0-9]*

.include "../../databases/mysql80-client/Makefile.common"

CMAKE_ARGS+=	-DINSTALL_INFODIR=${PKGINFODIR}
CMAKE_ARGS+=	-DWITH_PROTOBUF="system"
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/library_output_directory
# This is a hack for ${WRKSRC}/cmake/protobuf.cmake
CMAKE_ARGS+=	-DHOMEBREW_HOME=${PREFIX}

PLIST_VARS+=		auth_socket

USE_CXX_FEATURES+=	charconv

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
SMF_NAME=		mysql
SMF_METHODS=		${RCD_SCRIPTS}

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}
FILES_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
FILES_SUBST+=		MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
FILES_SUBST+=		MYSQL_PIDFILE=${MYSQL_PIDFILE}
MESSAGE_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
MESSAGE_SUBST+=		MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
BUILD_DEFS+=		MYSQL_DATADIR

REPLACE_PERL+=		mysql-test/lib/v1/mysql-test-run.pl
REPLACE_PERL+=		mysql-test/lib/t/SafeProcessStress.pl
REPLACE_PERL+=		mysql-test/lib/t/testMyConfig.t
REPLACE_PERL+=		mysql-test/lib/t/testMyConfigFactory.t
REPLACE_PERL+=		mysql-test/lib/t/test_child.pl
REPLACE_PERL+=		mysql-test/mysql-stress-test.pl
REPLACE_PERL+=		mysql-test/mysql-test-run.pl
REPLACE_PERL+=		mysql-test/suite/engines/rr_trx/run_stress_tx_rr.pl
REPLACE_PERL+=		mysql-test/suite/funcs_1/lib/DataGen_local.pl
REPLACE_PERL+=		mysql-test/suite/funcs_1/lib/DataGen_modify.pl
REPLACE_PERL+=		mysql-test/suite/funcs_2/lib/gen_charset_utf8.pl
REPLACE_PERL+=		mysql-test/suite/opt_trace/validate_json.pl
REPLACE_PERL+=		mysql-test/suite/rpl/extension/bhs.pl
REPLACE_PERL+=		mysql-test/suite/rpl/extension/checksum.pl
REPLACE_PERL+=		scripts/randomize-order.pl

REPLACE_SH+=		mysql-test/suite/rpl/t/rpl_loaddata_symlink-master.sh
REPLACE_SH+=		mysql-test/suite/rpl/t/rpl_loaddata_symlink-slave.sh
REPLACE_SH+=		mysql-test/suite/rpl/t/rpl_misc_functions-slave.sh
REPLACE_SH+=		mysql-test/suite/rpl_nogtid/t/rpl_misc_functions-slave.sh
REPLACE_SH+=		mysql-test/t/long_tmpdir-master.sh
REPLACE_SH+=		mysql-test/t/lowercase_mixed_tmpdir-master.sh
REPLACE_SH+=		mysql-test/t/lowercase_mixed_tmpdir_innodb-master.sh
REPLACE_SH+=		scripts/mysql_config.sh

SUBST_CLASSES+=		perlpath
SUBST_STAGE.perlpath=	pre-configure
SUBST_MESSAGE.perlpath=	Fixing Perl paths.
SUBST_FILES.perlpath+=	scripts/mysqld_multi.pl.in
SUBST_FILES.perlpath+=	scripts/mysqldumpslow.pl.in
SUBST_SED.perlpath=	-e 's,@PERL_PATH@,${PERL5},g'

INSTALLATION_DIRS+=	bin
TEST_TARGET=		test

CMAKE_ARGS+=		-DWITHOUT_CLIENTLIBS=ON

post-extract:
	${CP} ${FILESDIR}/ffsll.cc ${WRKSRC}/sql/
	${CHMOD} a-x ${WRKSRC}/mysql-test/std_data/datadir_tablespace_*

.include "../../devel/protobuf/buildlink3.mk"
BUILDLINK_AUTO_DIRS.mysql-client=	no
.include "../../databases/mysql80-client/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
