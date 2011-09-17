# $NetBSD: Makefile,v 1.6 2011/09/17 11:32:03 obache Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ldapdb/}
COMMENT=	Cyrus SASL LDAPDB authentication plugin
SASL_PLUGIN=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--enable-ldapdb

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libldapdb.la

.include "../../databases/openldap-client/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libldapdb.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
