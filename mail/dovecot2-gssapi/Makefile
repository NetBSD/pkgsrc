# $NetBSD: Makefile,v 1.4 2018/10/23 16:29:18 adam Exp $

.include "../../mail/dovecot2/Makefile.plugin"

PKGNAME=		${DISTNAME:S/dovecot/dovecot-gssapi/}
COMMENT+=		(GSSAPI plugin)

CONFIGURE_ARGS+=	--with-gssapi=plugin

INSTALLATION_DIRS+=	lib/dovecot/auth

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} 	\
		src/auth/libmech_gssapi.la 				\
		${DESTDIR}${PREFIX}/lib/dovecot/auth

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
