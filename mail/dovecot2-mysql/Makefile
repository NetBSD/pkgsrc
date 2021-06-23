# $NetBSD: Makefile,v 1.4 2021/06/23 20:33:12 nia Exp $

.include "../../mail/dovecot2/Makefile.common"

PKGNAME=	${DISTNAME:S/dovecot/dovecot-mysql/}
PKGREVISION=	1
COMMENT+=	(MySQL plugin)

CONFIGURE_ARGS+=	--with-sql=plugin
CONFIGURE_ARGS+=	--with-mysql

INSTALLATION_DIRS+=	lib/dovecot/auth lib/dovecot/dict

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} 	\
		src/lib-sql/libdriver_mysql.la 				\
		${DESTDIR}${PREFIX}/lib/dovecot
	${LN} -s ../libdriver_mysql.so 					\
		${DESTDIR}${PREFIX}/lib/dovecot/auth/libdriver_mysql.so
	${LN} -s ../libdriver_mysql.so 					\
		${DESTDIR}${PREFIX}/lib/dovecot/dict/libdriver_mysql.so

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
