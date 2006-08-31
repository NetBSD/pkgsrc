# $NetBSD: Makefile,v 1.31 2006/08/31 12:42:42 seb Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
SVR4_PKGNAME=		mysqs
COMMENT=		MySQL 4, a free SQL database (server)

CONFLICTS=		{mysql-server-[0-9]*,mysql3-server-[0-9]*}

.include "../../databases/mysql4-client/Makefile.common"


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
BUILD_DIRS=		${WRKSRC} ${WRKSRC}/man

.include "../../databases/mysql4-client/buildlink3.mk"
BUILDLINK_DEPMETHOD.readline=build
.include "../../devel/readline/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

post-configure:
	cd ${WRKSRC} && ${CP} -f config.h include/my_config.h

post-build:
	cd ${WRKSRC}/scripts && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		${MAKE_FLAGS} mysqld_safe mysql_install_db mysqldumpslow

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysqld_safe ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_install_db ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysqldumpslow ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/support-files/mysql.server ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_secure_installation.sh \
		${PREFIX}/bin/mysql_secure_installation

.include "../../mk/bsd.pkg.mk"
