# $NetBSD: Makefile,v 1.12 2012/10/02 21:25:22 asau Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
SVR4_PKGNAME=		mysqs
COMMENT=		MySQL 5, a free SQL database (server)

CONFLICTS=		{mysql-server-[0-9]*,mysql3-server-[0-9]*}

.include "../../databases/mysql51-client/Makefile.common"

CONFIGURE_ARGS+=	--with-libwrap
CONFIGURE_ARGS+=	--with-mysqld-user=${MYSQL_USER}

.if !empty(PKG_OPTIONS:Membedded-server)
CONFIGURE_ARGS+=	--with-embedded-privilege-control
CONFIGURE_ARGS+=	--with-embedded-server
CONFIGURE_ARGS+=	--with-pic
PLIST.embedded=		yes
.endif

.if !empty(PKG_OPTIONS:Mndb-cluster)
CONFIGURE_ARGS+=	--with-plugins=innobase,ndbcluster
REPLACE_PERL+=		storage/ndb/tools/ndb_error_reporter \
			storage/ndb/tools/ndb_size.pl
PLIST.ndb=		yes
BUILDLINK_DEPMETHOD.readline=	full
.else
CONFIGURE_ARGS+=	--with-plugins=innobase
.endif

.if !empty(PKG_OPTIONS:Mpstack)
CONFIGURE_ARGS+=	--with-pstack
PLIST.pstack=		yes
.endif

.if !empty(PKG_OPTIONS:Mmysqlmanager)
CONFIGURE_ARGS+=	--with-mysqlmanager
PLIST.manager=		yes
.endif

PLIST_VARS+=		embedded manager ndb pstack

PTHREAD_OPTS+=		require
CONFIGURE_ARGS+=	--with-pthread

PKG_GROUPS=		${MYSQL_GROUP}
PKG_USERS=		${MYSQL_USER}:${MYSQL_GROUP}

PKG_GECOS.${MYSQL_USER}=	MySQL database administrator
PKG_HOME.${MYSQL_USER}=		${MYSQL_DATADIR}
PKG_SHELL.${MYSQL_USER}=	${SH}

RCD_SCRIPTS=		mysqld

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q} \
			MYSQL_DATADIR=${MYSQL_DATADIR} \
			MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
MESSAGE_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR} \
			MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
BUILD_DEFS+=		MYSQL_DATADIR
BUILD_DIRS=		. man

REPLACE_PERL+=		mysql-test/lib/My/SafeProcess/safe_process.pl \
			mysql-test/lib/v1/mysql-test-run.pl \
			mysql-test/mysql-stress-test.pl \
			mysql-test/mysql-test-run.pl \
			mysql-test/suite/engines/rr_trx/run_stress_tx_rr.pl \
			mysql-test/suite/funcs_1/lib/DataGen_local.pl \
			mysql-test/suite/funcs_1/lib/DataGen_modify.pl \
			mysql-test/suite/funcs_2/lib/gen_charset_utf8.pl \
			mysql-test/mtr \
			scripts/mysqld_multi.sh

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=		-D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__
CXXFLAGS+=		-D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__
.endif

.include "../../databases/mysql51-client/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

# Only 'ndb_mgm' needs readline otherwise we only need it to placate the
# configure script.  As ndb_mgm is only build if the 'ndb-cluster' option
# is enabled that option sets a full dependency on readline otherwise 
# make this only a build-time dependency. 
#
BUILDLINK_DEPMETHOD.readline?=	build
.include "../../devel/readline/buildlink3.mk"

post-configure:
	cd ${WRKSRC}/include && cp -f config.h my_config.h
	${RM} -f ${WRKSRC}/mysql-test/mysql-test-run

post-build:
	cd ${WRKSRC}/scripts && \
	${BUILD_MAKE_CMD} mysqld_safe mysql_install_db

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysqld_safe \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_install_db \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/support-files/mysql.server \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/mysqld_multi.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
#	${INSTALL_MAN} ${WRKSRC}/man/mysqld_safe.1 \
#		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_secure_installation.sh \
		${DESTDIR}${PREFIX}/bin/mysql_secure_installation

.include "../../mk/bsd.pkg.mk"
