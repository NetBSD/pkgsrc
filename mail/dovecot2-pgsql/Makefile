# $NetBSD: Makefile,v 1.4 2018/11/30 18:43:09 adam Exp $

.include "../../mail/dovecot2/Makefile.common"

PKGNAME=	${DISTNAME:S/dovecot/dovecot-pgsql/}
COMMENT+=	(PostgreSQL plugin)

CONFIGURE_ARGS+=	--with-sql=plugin
CONFIGURE_ARGS+=	--with-pgsql

INSTALLATION_DIRS+=	lib/dovecot/auth lib/dovecot/dict

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} 	\
		src/lib-sql/libdriver_pgsql.la 				\
		${DESTDIR}${PREFIX}/lib/dovecot
	${LN} -s ../libdriver_pgsql.so 					\
		${DESTDIR}${PREFIX}/lib/dovecot/auth/libdriver_pgsql.so
	${LN} -s ../libdriver_pgsql.so 					\
		${DESTDIR}${PREFIX}/lib/dovecot/dict/libdriver_pgsql.so

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
