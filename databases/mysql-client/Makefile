# $NetBSD: Makefile,v 1.34 2004/11/09 06:11:48 xtraeme Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL 4, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-extra-tools
CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--enable-thread-safe-client
USE_BUILDLINK3=		yes
UNWRAP_FILES=		scripts/mysql_config

INFO_FILES=		mysql.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
