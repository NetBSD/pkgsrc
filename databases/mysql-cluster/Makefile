# $NetBSD: Makefile,v 1.16 2019/08/11 13:18:19 wiz Exp $

PKGNAME=		${DISTNAME:S/-gpl//}
PKGREVISION=		3
COMMENT=		MySQL Cluster 7.4, a free SQL clustered database

CONFLICTS=		mysql*-{client,server}-[0-9]*

.include "Makefile.common"

PKG_GROUPS=			${MYSQL_GROUP}
PKG_USERS=			${MYSQL_USER}:${MYSQL_GROUP}
PKG_GECOS.${MYSQL_USER}=	MySQL database administrator
PKG_HOME.${MYSQL_USER}=		${MYSQL_DATADIR}
PKG_SHELL.${MYSQL_USER}=	${SH}

UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes

RCD_SCRIPTS=		mysqld ndbd ndbmtd ndb_mgmd
SMF_NAME=		mysql-cluster
SMF_METHODS=		mysqld ndbd
SMF_INSTANCES=		mysqld ndbd ndb_mgmd

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}
FILES_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
FILES_SUBST+=		MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
MESSAGE_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
MESSAGE_SUBST+=		MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
BUILD_DEFS+=		MYSQL_DATADIR

CNFSUBST=		-e 's,@MYSQL_DATADIR@,${MYSQL_DATADIR},g'
CNFSUBST+=		-e 's,@PREFIX@,${PREFIX},g'
CNFSUBST+=		-e 's,@VARBASE@,${VARBASE},g'

CONF_FILES+=		share/mysql/my-cluster.cnf ${PKG_SYSCONFDIR}/my.cnf
CONF_FILES+=		share/mysql/mysql-cluster.ini
CONF_FILES+=		${PKG_SYSCONFDIR}/mysql-cluster.ini

REPLACE_PERL=		mysql-test/lib/v1/mysql-test-run.pl
REPLACE_PERL+=		mysql-test/mtr.out-of-source
REPLACE_PERL+=		mysql-test/mysql-stress-test.pl
REPLACE_PERL+=		mysql-test/mysql-test-run.pl
REPLACE_PERL+=		mysql-test/std_data/checkDBI_DBD-mysql.pl
REPLACE_PERL+=		mysql-test/suite/engines/rr_trx/run_stress_tx_rr.pl
REPLACE_PERL+=		mysql-test/suite/funcs_1/lib/DataGen_local.pl
REPLACE_PERL+=		mysql-test/suite/funcs_1/lib/DataGen_modify.pl
REPLACE_PERL+=		mysql-test/suite/funcs_2/lib/gen_charset_utf8.pl
REPLACE_PERL+=		mysql-test/suite/rpl/extension/bhs.pl
REPLACE_PERL+=		mysql-test/suite/rpl/extension/checksum.pl
REPLACE_PERL+=		scripts/mysql_convert_table_format.sh
REPLACE_PERL+=		scripts/mysql_find_rows.sh
REPLACE_PERL+=		scripts/mysql_fix_extensions.sh
REPLACE_PERL+=		scripts/mysql_install_db.pl.in
REPLACE_PERL+=		scripts/mysql_secure_installation.pl.in
REPLACE_PERL+=		scripts/mysql_setpermission.sh
REPLACE_PERL+=		scripts/mysql_zap.sh
REPLACE_PERL+=		scripts/mysqlaccess.sh
REPLACE_PERL+=		scripts/mysqld_multi.sh
REPLACE_PERL+=		scripts/mysqldumpslow.sh
REPLACE_PERL+=		scripts/mysqlhotcopy.sh
REPLACE_PERL+=		sql-bench/bench-count-distinct.sh
REPLACE_PERL+=		sql-bench/bench-init.pl.sh
REPLACE_PERL+=		sql-bench/compare-results.sh
REPLACE_PERL+=		sql-bench/copy-db.sh
REPLACE_PERL+=		sql-bench/crash-me.sh
REPLACE_PERL+=		sql-bench/graph-compare-results.sh
REPLACE_PERL+=		sql-bench/innotest1.sh
REPLACE_PERL+=		sql-bench/innotest1a.sh
REPLACE_PERL+=		sql-bench/innotest1b.sh
REPLACE_PERL+=		sql-bench/innotest2.sh
REPLACE_PERL+=		sql-bench/innotest2a.sh
REPLACE_PERL+=		sql-bench/innotest2b.sh
REPLACE_PERL+=		sql-bench/run-all-tests.sh
REPLACE_PERL+=		sql-bench/server-cfg.sh
REPLACE_PERL+=		sql-bench/test-ATIS.sh
REPLACE_PERL+=		sql-bench/test-alter-table.sh
REPLACE_PERL+=		sql-bench/test-big-tables.sh
REPLACE_PERL+=		sql-bench/test-connect.sh
REPLACE_PERL+=		sql-bench/test-create.sh
REPLACE_PERL+=		sql-bench/test-insert.sh
REPLACE_PERL+=		sql-bench/test-select.sh
REPLACE_PERL+=		sql-bench/test-transactions.sh
REPLACE_PERL+=		sql-bench/test-wisconsin.sh
REPLACE_PERL+=		storage/ndb/memcache/memclient.pl
REPLACE_PERL+=		storage/ndb/tools/ndb_error_reporter.pl
REPLACE_PERL+=		storage/ndb/tools/ndb_size.pl

REPLACE_PYTHON=		mysql-test/suite/opt_trace/validate_json.py
REPLACE_PYTHON+=	storage/ndb/mcc/ndb_setup.py
REPLACE_PYTHON+=	storage/ndb/mcc/tst/tstcli.py

REPLACE_SH=		mysql-test/suite/rpl/t/rpl_loaddata_symlink-master.sh
REPLACE_SH+=		mysql-test/suite/rpl/t/rpl_loaddata_symlink-slave.sh
REPLACE_SH+=		mysql-test/suite/rpl/t/rpl_misc_functions-slave.sh
REPLACE_SH+=		mysql-test/t/long_tmpdir-master.sh
REPLACE_SH+=		mysql-test/t/lowercase_mixed_tmpdir-master.sh
REPLACE_SH+=		mysql-test/t/lowercase_mixed_tmpdir_innodb-master.sh
REPLACE_SH+=		scripts/mysql_install_db.sh
REPLACE_SH+=		scripts/mysql_secure_installation.sh
REPLACE_SH+=		scripts/mysql_secure_installation.sh

pre-build:
	${RM} -f ${WRKSRC}/storage/ndb/mcc/frontend/dojo/dojox/mobile/build/build.sh.orig

post-install:
	${SED} ${CNFSUBST} ${FILESDIR}/my-cluster.cnf \
		> ${DESTDIR}${PREFIX}/share/mysql/my-cluster.cnf
	${SED} ${CNFSUBST} ${FILESDIR}/mysql-cluster.ini \
		> ${DESTDIR}${PREFIX}/share/mysql/mysql-cluster.ini

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
