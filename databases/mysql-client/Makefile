# $NetBSD: Makefile,v 1.21 2002/12/13 14:19:54 tron Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		2
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL, a free SQL database (client)

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-server
USE_BUILDLINK2=		YES

INFO_FILES=		mysql.info

post-install:
	cd ${PREFIX}/man/man1; ${RM} -f mysqld.1 safe_mysqld.1
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
