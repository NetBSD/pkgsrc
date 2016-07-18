# $NetBSD: Makefile,v 1.1 2016/07/18 15:03:06 fhajny Exp $
#

.include "../../mail/dovecot2/Makefile.plugin"

PKGNAME=		${DISTNAME:S/dovecot/dovecot-pgsql/}
COMMENT+=		(pgsql plugin)

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
