# $NetBSD: Makefile,v 1.26 2008/03/06 16:01:42 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		3
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL 4, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-extra-tools
CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--enable-thread-safe-client
UNWRAP_FILES=		scripts/mysql_config
INFO_FILES=		# PLIST

INSTALLATION_DIRS=	${PKGINFODIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info \
		${DESTDIR}${PREFIX}/${PKGINFODIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/mysql
.for f in huge large innodb-heavy-4G small medium
	${INSTALL_DATA} ${WRKSRC}/support-files/my-${f}.cnf.sh \
		${DESTDIR}${PREFIX}/share/examples/mysql/my-${f}.cnf
.endfor

# We need the full readline on NetBSD<2.0.
INCOMPAT_READLINE+=	NetBSD-[0-1].*-*
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
