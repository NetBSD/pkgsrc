# $NetBSD: Makefile,v 1.56 2004/10/03 00:13:21 tv Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
PKGREVISION=	1
SVR4_PKGNAME=		mysqs
COMMENT=		MySQL 3, a free SQL database (server)

.include "../../databases/mysql-client/Makefile.common"

CONFIGURE_ARGS+=	--without-berkeley-db
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make

USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

PTHREAD_OPTS=		require

CONFIGURE_ARGS+=	--with-pthreads

PKG_USERS=		${MYSQL_USER}:${MYSQL_GROUP}::MySQL\\ database\\ administrator:${MYSQL_DATADIR}:${SH}
PKG_GROUPS=		${MYSQL_GROUP}
RCD_SCRIPTS=		mysqld
CONFIGURE_ARGS+=	--with-mysqld-user=${MYSQL_USER}
FILES_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
FILES_SUBST+=		MYSQL_USER=${MYSQL_USER}
FILES_SUBST+=		MYSQL_GROUP=${MYSQL_GROUP}
MESSAGE_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR} \
			MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
BUILD_DEFS+=		MYSQL_DATADIR
OWN_DIRS_PERMS+=	${MYSQL_DATADIR} ${MYSQL_USER} ${MYSQL_GROUP} 0700

# XXX TCP wrapper support is broken on (at least) Linux and Solaris.
# ref: http://bugs.mysql.com/bug.php?id=599
#      http://mail-index.netbsd.org/tech-pkg/2003/08/07/0003.html
.if ${OPSYS} != "Linux" && ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=	--with-libwrap
.  include "../../security/tcp_wrappers/buildlink3.mk"
.endif

post-configure:
	cd ${WRKSRC} && ${CP} -f config.h include/my_config.h

post-build:
	cd ${WRKSRC}/scripts && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		${MAKE_FLAGS} safe_mysqld mysql_install_db

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/safe_mysqld ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_install_db ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/support-files/mysql.server ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/mysqld.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/safe_mysqld.1 ${PREFIX}/man/man1

.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/mysql-client/buildlink3.mk"

.if ${PTHREAD_TYPE} == "pth"
CFLAGS+=	-DSIGNALS_DONT_BREAK_READ
CXXFLAGS+=	-DSIGNALS_DONT_BREAK_READ
CONFIGURE_ENV+=	ac_cv_func_pthread_setschedparam=no
CONFIGURE_ENV+=	ac_cv_func_pthread_attr_setschedparam=no
.endif

.include "../../mk/bsd.pkg.mk"
