# $NetBSD: Makefile,v 1.12 2004/11/08 18:19:41 xtraeme Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		2
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL 4, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

USE_BUILDLINK3=		yes

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-extra-tools
CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--enable-thread-safe-client
UNWRAP_FILES=		scripts/mysql_config

INFO_FILES=		mysql.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
