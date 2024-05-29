# $NetBSD: Makefile,v 1.35 2024/05/29 16:33:20 adam Exp $

PKGREVISION= 3
.include "../../mail/dovecot2/Makefile.common"

PKGNAME=	${DISTNAME:S/dovecot/dovecot-sqlite/}
COMMENT+=	(SQLite plugin)

CONFIGURE_ARGS+=	--with-sql=plugin
CONFIGURE_ARGS+=	--with-sqlite

INSTALLATION_DIRS+=	lib/dovecot/auth lib/dovecot/dict

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} 	\
		src/lib-sql/libdriver_sqlite.la 			\
		${DESTDIR}${PREFIX}/lib/dovecot
	${LN} -s ../libdriver_sqlite.so 				\
		${DESTDIR}${PREFIX}/lib/dovecot/auth/libdriver_sqlite.so
	${LN} -s ../libdriver_sqlite.so 				\
		${DESTDIR}${PREFIX}/lib/dovecot/dict/libdriver_sqlite.so

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
