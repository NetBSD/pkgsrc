# $NetBSD: Makefile,v 1.3 2005/01/20 14:15:04 xtraeme Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		3
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL 3, a free SQL database (client)

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-server
USE_BUILDLINK3=		YES

USE_NEW_TEXINFO=	YES
INFO_FILES=		mysql.info

post-install:
	cd ${PREFIX}/man/man1; ${RM} -f mysqld.1 safe_mysqld.1
	cd ${PREFIX}/share/mysql; ${RM} -f mysql.server
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
