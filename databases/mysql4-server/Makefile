# $NetBSD: Makefile,v 1.5 2004/04/22 14:31:35 seb Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
PKGREVISION=		2
SVR4_PKGNAME=		mysqs
COMMENT=		MySQL, a free SQL database (server)

.include "../mysql4-client/Makefile.common"

CONFIGURE_ARGS+=	--with-libwrap
CONFIGURE_ARGS+=	--with-raid
CONFIGURE_ARGS+=	--without-berkeley-db
CONFIGURE_ARGS+=	--without-mysqlfs
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

CONFLICTS=		{mysql-server-[0-9]*,mysql3-server-[0-9]*}

PTHREAD_OPTS=		require

CONFIGURE_ARGS+=	--with-pthreads

PKG_USERS=		${MYSQL_USER}:${MYSQL_GROUP}::MySQL\\ database\\ administrator:${MYSQL_DATADIR}:${SH}
PKG_GROUPS=		${MYSQL_GROUP}
RCD_SCRIPTS=		mysqld
CONFIGURE_ARGS+=	--with-mysqld-user=${MYSQL_USER}
FILES_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
MESSAGE_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR} \
			MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
BUILD_DEFS+=		MYSQL_DATADIR
MAKE_DIRS_PERMS+=	${MYSQL_DATADIR} ${MYSQL_USER} ${MYSQL_GROUP} 0700

post-configure:
	cd ${WRKSRC} && ${CP} -f config.h include/my_config.h

post-build:
	cd ${WRKSRC}/man && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	cd ${WRKSRC}/scripts && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		${MAKE_FLAGS} mysqld_safe mysql_install_db

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysqld_safe ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_install_db ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/support-files/mysql.server ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/mysqld.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/mysqld_multi.1 ${PREFIX}/man/man1
	#${INSTALL_MAN} ${WRKSRC}/man/mysqld_safe.1 ${PREFIX}/man/man1
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL
	${CHOWN} -R ${MYSQL_USER}:${MYSQL_GROUP} ${MYSQL_DATADIR}

.include "../../databases/mysql4-client/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
CFLAGS+=	-DSIGNALS_DONT_BREAK_READ
CXXFLAGS+=	-DSIGNALS_DONT_BREAK_READ
CONFIGURE_ENV+=	ac_cv_func_pthread_setschedparam=no
CONFIGURE_ENV+=	ac_cv_func_pthread_attr_setschedparam=no
.endif

.include "../../mk/bsd.pkg.mk"
