# $NetBSD: Makefile,v 1.13 2018/04/17 01:57:18 christos Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ldapdb/}
#PKGREVISION=	4
COMMENT=	Cyrus SASL LDAPDB authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--enable-ldapdb

BUILD_DIRS=	plugins
BUILD_TARGET=	libldapdb.la

.include "../../databases/openldap-client/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libldapdb.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
