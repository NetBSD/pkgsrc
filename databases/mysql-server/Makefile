# $NetBSD: Makefile,v 1.47 2003/09/19 14:34:58 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
PKGREVISION=		6
SVR4_PKGNAME=		mysqs
COMMENT=		MySQL, a free SQL database (server)

.include "../../databases/mysql-client/Makefile.common"

CONFIGURE_ARGS+=	--with-libwrap
CONFIGURE_ARGS+=	--without-berkeley-db
USE_BUILDLINK2=		YES
USE_GMAKE=		YES

USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

ONLY_FOR_PLATFORM=	SunOS-*-sparc Linux-*-*

# on NetBSD, if native threads are not available, hardwire
# included mit-pthreads, as this doesn't yet work properly with pth
.if ${OPSYS} == "NetBSD"
.  if exists(/usr/include/pthread.h)

# native pthreads
ONLY_FOR_PLATFORM+=	NetBSD-*-*
.  else

# force included mit-pthreads
CONFIGURE_ARGS+=	--with-mit-threads

# platforms on which included mit-pthreads is usable
ONLY_FOR_PLATFORM+=	NetBSD-*-alpha NetBSD-*-arm NetBSD-*-arm32	\
			NetBSD-*-i386 NetBSD-*-sparc NetBSD-*-m68k	\
			NetBSD-*-powerpc
.  endif
.endif

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

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
