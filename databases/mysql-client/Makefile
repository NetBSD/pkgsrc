# $NetBSD: Makefile,v 1.36 2004/11/16 17:29:36 tron Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
SVR4_PKGNAME=		mysqc
PKGREVISION=		2
COMMENT=		MySQL 4, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-extra-tools
CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--enable-thread-safe-client
USE_BUILDLINK3=		yes
UNWRAP_FILES=		scripts/mysql_config

INFO_FILES=		mysql.info

post-configure:
	${SED} -e 's#${PTHREAD_CFLAGS}##g' -e 's#${PTHREAD_LDFLAGS}##g' \
	   -e 's#${PTHREAD_LIBS}##g' ${WRKSRC}/libmysql/Makefile \
	   >${WRKSRC}/libmysql/Makefile.new
	${MV} ${WRKSRC}/libmysql/Makefile.new ${WRKSRC}/libmysql/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
