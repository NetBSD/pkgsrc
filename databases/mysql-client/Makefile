# $NetBSD: Makefile,v 1.17.2.2 2002/06/21 23:05:02 jlam Exp $
#

PKGNAME=		${DISTNAME:S/-/-client-/}
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL, a free SQL database (client)

USE_BUILDLINK2=		YES

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-server

INFO_FILES=		mysql.info

post-install:
	cd ${PREFIX}/man/man1; ${RM} -f mysqld.1 safe_mysqld.1
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
