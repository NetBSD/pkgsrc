# $NetBSD: Makefile,v 1.30 2004/04/03 16:06:16 schmonz Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL, a free SQL database (client)

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
