# $NetBSD: Makefile,v 1.11 2020/04/16 09:03:47 manu Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
#PKGREVISION=	1
COMMENT=	MariaDB 5.5, a free SQL database (client)

CONFLICTS=	mysql3-client-[0-9]*
CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=		-DWITHOUT_SERVER=ON
CMAKE_ARGS+=		-DWITH_UNIT_TESTS=OFF
# MariaDB uses internal OpenSSL structure made opaque with later versions
CMAKE_ARGS+=		-DWITH_SSL=bundled
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes
INSTALL_DIRS+=		client include libmysql man scripts tests

REPLACE_PERL+=	scripts/mysql_convert_table_format.sh
REPLACE_PERL+=	scripts/mysql_find_rows.sh
REPLACE_PERL+=	scripts/mysql_fix_extensions.sh
REPLACE_PERL+=	scripts/mysql_fix_privilege_tables.sh
REPLACE_PERL+=	scripts/mysql_setpermission.sh
REPLACE_PERL+=	scripts/mysql_zap.sh
REPLACE_PERL+=	scripts/mysqlaccess.sh
REPLACE_PERL+=	scripts/mysqld_multi.sh
REPLACE_PERL+=	scripts/mysqldumpslow.sh
REPLACE_PERL+=	scripts/mysqlhotcopy.sh
REPLACE_PERL+=	scripts/mytop.sh

# REPLACE_PERL doesn't replace @PERL_PATH@, which is what's found in these
# files now.
SUBST_CLASSES+=		perlpath
SUBST_STAGE.perlpath=	pre-configure
SUBST_FILES.perlpath=	${REPLACE_PERL}
SUBST_SED.perlpath=	-e s,@PERL_PATH@,perl,

SUBST_CLASSES+=		fixwrap
SUBST_STAGE.fixwrap=	post-build
SUBST_FILES.fixwrap=	scripts/mysqlbug
SUBST_SED.fixwrap=	-e "s,${WRAPPER_BINDIR}/,,g"

# Replace manual pages which only include other ones with a symbolic link.
# It is for manual compression is activated or mandoc(1) is used.
post-install:
.for mf in mysql_client_test_embedded.1 mysqltest_embedded.1
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${mf}
	${LN} -s ${mf:S/_embedded//} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${mf}
.endfor

.include "../../mk/bsd.pkg.mk"
