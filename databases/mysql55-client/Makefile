# $NetBSD: Makefile,v 1.11 2013/07/31 18:51:41 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
SVR4_PKGNAME=	mysqc
COMMENT=	MySQL 5, a free SQL database (client)

CONFLICTS=	{mysql-client-[0-9]*,mysql3-client-[0-9]*}

.include "Makefile.common"

CMAKE_ARGS+=		-DWITHOUT_SERVER=ON
CMAKE_ARGS+=		-DWITH_UNIT_TESTS=OFF
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes
INSTALL_DIRS+=		client include libmysql man scripts tests

REPLACE_PERL=	scripts/mysql_convert_table_format.sh
REPLACE_PERL+=	scripts/mysql_find_rows.sh
REPLACE_PERL+=	scripts/mysql_fix_extensions.sh
REPLACE_PERL+=	scripts/mysql_fix_privilege_tables.sh
REPLACE_PERL+=	scripts/mysql_setpermission.sh
REPLACE_PERL+=	scripts/mysql_zap.sh
REPLACE_PERL+=	scripts/mysqlaccess.sh
REPLACE_PERL+=	scripts/mysqld_multi.sh
REPLACE_PERL+=	scripts/mysqldumpslow.sh
REPLACE_PERL+=	scripts/mysqlhotcopy.sh

# Replace manual pages which only include other ones with a symbolic link
# if manual compression is activated. The manual pages won't work otherwise.
.if defined(MANZ)
post-install:
.  for mf in mysql_client_test_embedded.1 mysqltest_embedded.1
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${mf}
	${LN} -s ${mf:S/_embedded//} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${mf}
.  endfor
.endif

.include "../../mk/bsd.pkg.mk"
