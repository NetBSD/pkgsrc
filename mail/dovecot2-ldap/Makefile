# $NetBSD: Makefile,v 1.4 2018/11/30 18:43:09 adam Exp $

.include "../../mail/dovecot2/Makefile.common"

PKGNAME=	${DISTNAME:S/dovecot/dovecot-ldap/}
COMMENT+=	(LDAP plugin)

CONFIGURE_ARGS+=	--with-ldap=plugin

INSTALLATION_DIRS+=	include/dovecot \
			lib/dovecot/auth lib/dovecot/dict

do-install:
	cd ${WRKSRC} && \
		${LIBTOOL} --mode=install ${INSTALL_LIB} \
			src/auth/libauthdb_ldap.la \
			${DESTDIR}${PREFIX}/lib/dovecot/auth && \
		${LIBTOOL} --mode=install ${INSTALL_LIB} \
			src/lib-ldap/libdovecot-ldap.la \
			${DESTDIR}${PREFIX}/lib/dovecot && \
		${LIBTOOL} --mode=install ${INSTALL_LIB} \
			src/lib-dict-backend/libdict_ldap.la \
			${DESTDIR}${PREFIX}/lib/dovecot/dict
	${INSTALL_DATA} ${WRKSRC}/src/lib-ldap/ldap-client.h \
		${DESTDIR}${PREFIX}/include/dovecot

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
