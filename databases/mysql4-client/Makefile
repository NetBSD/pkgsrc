# $NetBSD: Makefile,v 1.8 2004/10/03 00:13:21 tv Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		1
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL 4, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-server
USE_BUILDLINK3=		yes
UNWRAP_FILES=		scripts/mysql_config

INFO_FILES=		mysql.info

post-install:
	cd ${PREFIX}/man/man1 && \
		 ${RM} -f mysqld.1 mysqld_multi.1 mysqld_safe.1 safe_mysqld.1
	cd ${PREFIX}/share/mysql && ${RM} -f mysql.server
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
