# $NetBSD: Makefile,v 1.5 2004/06/20 18:48:44 xtraeme Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL 4, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-server
USE_BUILDLINK3=		YES

INFO_FILES=		mysql.info

post-install:
	cd ${PREFIX}/man/man1 && \
		 ${RM} -f mysqld.1 mysqld_multi.1 mysqld_safe.1 safe_mysqld.1
	cd ${PREFIX}/share/mysql && ${RM} -f mysql.server
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
