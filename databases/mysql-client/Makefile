# $NetBSD: Makefile,v 1.26 2003/09/28 09:03:52 jdolecek Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		1
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL, a free SQL database (client)

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-server
USE_BUILDLINK2=		YES

INFO_FILES=		mysql.info

post-install:
	cd ${PREFIX}/man/man1; ${RM} -f mysqld.1 safe_mysqld.1
	cd ${PREFIX}/share/mysql; ${RM} -f mysql.server
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
