# $NetBSD: Makefile,v 1.18 2002/06/16 21:45:45 wiz Exp $
#

.include "Makefile.common"

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		1
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
