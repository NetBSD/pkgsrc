# $NetBSD: Makefile,v 1.40 2009/05/20 00:58:10 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
PKGREVISION=		4
SVR4_PKGNAME=		mysqs
COMMENT=		MySQL 4, a free SQL database (server)

CONFLICTS=		{mysql-server-[0-9]*,mysql3-server-[0-9]*}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/mysql4-client/Makefile.common"

REPLACE_PERL+=		mysql-test/mysql-test-run.pl
# No dependency on Perl.

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

INSTALLATION_DIRS=	bin

.include "../../databases/mysql4-client/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

# We only need readline to placate the configure script.  None of the
# binaries are actually linked against -lreadline, so make this only
# a build-time dependency.
#
BUILDLINK_DEPMETHOD.readline=	build
.include "../../devel/readline/buildlink3.mk"

post-extract:
	chmod -x ${WRKSRC}/mysql-test/mysql-test-run.pl

post-configure:
	cd ${WRKSRC} && ${CP} -f config.h include/my_config.h

post-build:
	cd ${WRKSRC}/scripts && \
	${BUILD_MAKE_CMD} mysqld_safe mysql_install_db mysqldumpslow

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysqld_safe \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_install_db \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysqldumpslow \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/support-files/mysql.server \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_secure_installation.sh \
		${DESTDIR}${PREFIX}/bin/mysql_secure_installation

.include "../../mk/bsd.pkg.mk"
