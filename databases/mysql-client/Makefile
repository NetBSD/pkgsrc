# $NetBSD: Makefile,v 1.17 2002/02/18 15:14:06 seb Exp $
#

.include "Makefile.common"

PKGNAME=		${DISTNAME:S/-/-client-/}
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL, a free SQL database (client)

USE_BUILDLINK_ONLY=	YES
REPLACE_BUILDLINK+=	scripts/mysql_config
REPLACE_BUILDLINK+=	scripts/mysqlbug

CONFIGURE_ARGS+=	--without-server

INFO_FILES=		mysql.info

post-install:
	cd ${PREFIX}/man/man1; ${RM} -f mysqld.1 safe_mysqld.1
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
