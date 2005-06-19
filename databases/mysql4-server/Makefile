# $NetBSD: Makefile,v 1.19 2005/06/19 21:12:36 seb Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
PKGREVISION=		1
SVR4_PKGNAME=		mysqs
COMMENT=		MySQL 4, a free SQL database (server)

CONFLICTS=		{mysql-server-[0-9]*,mysql3-server-[0-9]*}

.include "../mysql4-client/Makefile.common"


CONFIGURE_ARGS+=	--with-libwrap
CONFIGURE_ARGS+=	--with-raid
CONFIGURE_ARGS+=	--without-berkeley-db
CONFIGURE_ARGS+=	--without-mysqlfs
CONFIGURE_ARGS+=	--with-mysqld-user=${MYSQL_USER}

PTHREAD_OPTS+=		require
CONFIGURE_ARGS+=	--with-pthreads

USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL

PKG_USERS=		${MYSQL_USER}:${MYSQL_GROUP}::MySQL\\ database\\ administrator:${MYSQL_DATADIR}:${SH}
PKG_GROUPS=		${MYSQL_GROUP}
RCD_SCRIPTS=		mysqld

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD} \
			MYSQL_DATADIR=${MYSQL_DATADIR} \
			MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
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
		${MAKE_FLAGS} mysqld_safe mysql_install_db

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysqld_safe ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_install_db ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/support-files/mysql.server ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/mysqld.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/mysqld_multi.1 ${PREFIX}/man/man1
	#${INSTALL_MAN} ${WRKSRC}/man/mysqld_safe.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_secure_installation.sh \
		${PREFIX}/bin/mysql_secure_installation

.include "../../mk/bsd.pkg.mk"
