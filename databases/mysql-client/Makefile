# $NetBSD: Makefile,v 1.20 2002/09/20 10:39:06 jlam Exp $
#

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		1
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL, a free SQL database (client)

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-server

INFO_FILES=		mysql.info

post-install:
	cd ${PREFIX}/man/man1; ${RM} -f mysqld.1 safe_mysqld.1
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
