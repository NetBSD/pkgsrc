# $NetBSD: Makefile,v 1.25 2008/01/18 05:06:27 tnn Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		1
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL 4, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-extra-tools
CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--enable-thread-safe-client
UNWRAP_FILES=		scripts/mysql_config
INFO_FILES=		# PLIST

post-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mysql
.for f in huge large innodb-heavy-4G small medium
	${INSTALL_DATA} ${WRKSRC}/support-files/my-${f}.cnf.sh \
		${PREFIX}/share/examples/mysql/my-${f}.cnf
.endfor

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
