# $NetBSD: Makefile,v 1.1.1.1 2003/05/14 04:17:31 salo Exp $
#

DISTNAME=	dovecot-0.99.9.1
CATEGORIES=	mail
MASTER_SITES=	http://dovecot.procontrol.fi/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	freebsd.patch fetch.patch

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://dovecot.procontrol.fi/
COMMENT=	Secure IMAP and POP3 server

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
USE_PKGINSTALL= YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--with-ssldir=/etc/openssl

DOVECOT_USE_GNUTLS?=	NO

.if !empty(DOVECOT_USE_GNUTLS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ssl=gnutls
.include "../../security/gnutls/buildlink2.mk"
.else
CONFIGURE_ARGS+=        --enable-ssl=openssl
.include "../../security/openssl/buildlink2.mk"
.endif

DOVECOT_USE_LDAP?=	NO

.if !empty(DOVECOT_USE_LDAP:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-ldap
.include "../../databases/openldap/buildlink2.mk"
.endif

DOVECOT_USE_PGSQL?=	NO

.if !empty(DOVECOT_USE_PGSQL:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-pgsql
CPPFLAGS=		-I${BUILDLINK_DIR}/include/pgsql
.include "../../databases/postgresql-lib/buildlink2.mk"
.endif

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
BUILD_DEFS+=		USE_INET6
CONFIGURE_ARGS+=	--enable-ipv6
.endif

RCD_SCRIPTS=	dovecot

DOVECOT_USER?=	dovecot
DOVECOT_GROUP?=	dovecot
PKG_GROUPS=	${DOVECOT_GROUP}
PKG_USERS=	${DOVECOT_USER}:${DOVECOT_GROUP}::Dovecot\\ IMAP/POP3\\ user

EGDIR=		${PREFIX}/share/examples/dovecot
CONF_FILES=	${EGDIR}/dovecot.conf.default ${PKG_SYSCONFDIR}/dovecot.conf

post-configure:
	@cd ${WRKSRC} &&						\
	(								\
		${MV} dovecot-example.conf dovecot-example.conf.orig;	\
		${SED} ${FILES_SUBST_SED} dovecot-example.conf.orig >	\
			dovecot-example.conf;				\
	)

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf	\
		${EGDIR}/dovecot.conf.default
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-* ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${EGDIR}

.include "../../mk/bsd.pkg.mk"
