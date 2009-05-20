# $NetBSD: Makefile,v 1.30 2009/05/20 00:58:10 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		4
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL 4, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-extra-tools
CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--enable-thread-safe-client
UNWRAP_FILES=		scripts/mysql_config
INFO_FILES=		yes

INSTALLATION_DIRS=	${PKGINFODIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info \
		${DESTDIR}${PREFIX}/${PKGINFODIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/mysql
.for f in huge large innodb-heavy-4G small medium
	${INSTALL_DATA} ${WRKSRC}/support-files/my-${f}.cnf.sh \
		${DESTDIR}${PREFIX}/share/examples/mysql/my-${f}.cnf
.endfor

.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
