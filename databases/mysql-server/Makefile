# $NetBSD: Makefile,v 1.29 2002/09/20 10:39:07 jlam Exp $
#

PKGNAME=		${DISTNAME:S/-/-server-/}
SVR4_PKGNAME=		mysqs
COMMENT=		MySQL, a free SQL database (server)

.include "../mysql-client/Makefile.common"

DEPENDS+=		${DISTNAME:S/-/-client>=/}:../../databases/mysql-client

# hardwire use of included mit-pthreads on NetBSD
.if (${OPSYS} == "NetBSD")
CONFIGURE_ARGS+=	--with-mit-threads
.endif

CONFIGURE_ARGS+=	--with-libwrap
CONFIGURE_ARGS+=	--without-berkeley-db

# platforms on which included mit-pthreads is usable
ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386	\
			NetBSD-*-sparc NetBSD-*-m68k SunOS-*-sparc	\
			NetBSD-*-powerpc Linux-*-*

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

post-configure:
	cd ${WRKSRC} && ${CP} -f config.h include/my_config.h

post-build:
	cd ${WRKSRC}/scripts && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		${MAKE_FLAGS} safe_mysqld mysql_install_db

pre-install:
	${SED}	-e "s|@MYSQL_DATADIR@|${MYSQL_DATADIR}|g"		\
		-e "s|@CAT@|${CAT}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/safe_mysqld ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_install_db ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/mysqld.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/safe_mysqld.1 ${PREFIX}/man/man1
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
