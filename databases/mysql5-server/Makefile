# $NetBSD: Makefile,v 1.20 2007/12/14 13:36:53 tron Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
SVR4_PKGNAME=		mysqs
COMMENT=		MySQL 5, a free SQL database (server)

CONFLICTS=		{mysql-server-[0-9]*,mysql3-server-[0-9]*}

.include "../../databases/mysql5-client/Makefile.common"

MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--with-libwrap
CONFIGURE_ARGS+=	--with-raid
CONFIGURE_ARGS+=	--without-berkeley-db
CONFIGURE_ARGS+=	--without-mysqlfs
CONFIGURE_ARGS+=	--with-mysqld-user=${MYSQL_USER:Q}

PTHREAD_OPTS+=		require
CONFIGURE_ARGS+=	--with-pthreads

PKG_GROUPS=		${MYSQL_GROUP}
PKG_USERS=		${MYSQL_USER}:${MYSQL_GROUP}

PKG_GECOS.${MYSQL_USER}=	MySQL database administrator
PKG_HOME.${MYSQL_USER}=		${MYSQL_DATADIR}
PKG_SHELL.${MYSQL_USER}=	${SH}

RCD_SCRIPTS=		mysqld

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q} \
			MYSQL_DATADIR=${MYSQL_DATADIR:Q} \
			MYSQL_USER=${MYSQL_USER:Q} MYSQL_GROUP=${MYSQL_GROUP:Q}
MESSAGE_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR} \
			MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
BUILD_DEFS+=		MYSQL_DATADIR
BUILD_DIRS=		. man

REPLACE_PERL+=		mysql-test/mysql-test-run.pl \
			mysql-test/suite/funcs_1/lib/DataGen_local.pl \
			mysql-test/suite/funcs_1/lib/DataGen_modify.pl \
			mysql-test/suite/funcs_2/lib/gen_charset_utf8.pl \
			mysql-test/mysql-stress-test.pl

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=		-D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__
CXXFLAGS+=		-D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__
.endif

.include "../../databases/mysql5-client/buildlink3.mk"
BUILDLINK_DEPMETHOD.readline=build
.include "../../devel/readline/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

post-configure:
	cd ${WRKSRC}/include && cp -f config.h my_config.h

post-build:
	cd ${WRKSRC}/scripts && env ${MAKE_ENV} ${MAKE_PROGRAM}	\
		${MAKE_FLAGS} mysqld_safe mysql_install_db

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysqld_safe ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_install_db ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/support-files/mysql.server ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/mysqld_multi.1 ${PREFIX}/${PKGMANDIR}/man1
	#${INSTALL_MAN} ${WRKSRC}/man/mysqld_safe.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_secure_installation.sh \
		${PREFIX}/bin/mysql_secure_installation

.include "../../mk/bsd.pkg.mk"
