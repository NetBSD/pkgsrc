# $NetBSD: Makefile,v 1.1.1.1 2006/11/25 13:35:25 obache Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ldapdb/}
COMMENT=	Cyrus SASL LDAPDB authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--enable-ldapdb

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libldapdb.la

.include "../../databases/openldap-client/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libldapdb.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
