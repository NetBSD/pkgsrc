# $NetBSD: Makefile,v 1.26 2018/08/22 09:43:12 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	1
COMMENT=	MySQL 5, a free SQL database (client)

CONFLICTS=	mysql3-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=		-DWITHOUT_SERVER=ON
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes
INSTALL_DIRS+=		client include libmysql man scripts tests

SUBST_CLASSES+=		perlpath
SUBST_STAGE.perlpath=	pre-configure
SUBST_MESSAGE.perlpath=	Fixing Perl paths.
SUBST_FILES.perlpath=	scripts/mysql_convert_table_format.sh
SUBST_FILES.perlpath+=	scripts/mysql_find_rows.sh
SUBST_FILES.perlpath+=	scripts/mysql_fix_extensions.sh
SUBST_FILES.perlpath+=	scripts/mysql_install_db.pl.in
SUBST_FILES.perlpath+=	scripts/mysql_secure_installation.pl.in
SUBST_FILES.perlpath+=	scripts/mysql_setpermission.sh
SUBST_FILES.perlpath+=	scripts/mysql_zap.sh
SUBST_FILES.perlpath+=	scripts/mysqlaccess.sh
SUBST_FILES.perlpath+=	scripts/mysqld_multi.sh
SUBST_FILES.perlpath+=	scripts/mysqldumpslow.sh
SUBST_FILES.perlpath+=	scripts/mysqlhotcopy.sh
SUBST_SED.perlpath=	-e 's,@PERL_PATH@,${PERL5},g'

SUBST_CLASSES+=		fixwrap
SUBST_STAGE.fixwrap=	post-build
SUBST_FILES.fixwrap=	scripts/mysqlbug
SUBST_SED.fixwrap=	-e "s,${WRAPPER_BINDIR}/,,g"

# Replace manual pages which only include other ones with a symbolic link
# It is for manual compression is activated or mandoc(1) is used.
post-install:
.for mf in mysql_client_test_embedded.1 mysqltest_embedded.1
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${mf}
	${LN} -s ${mf:S/_embedded//} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${mf}
.endfor

.include "../../mk/bsd.pkg.mk"
