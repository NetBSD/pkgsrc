# $NetBSD: Makefile,v 1.25 2004/08/01 05:17:19 schmonz Exp $

DISTNAME=		dovecot-0.99.10.9
CATEGORIES=		mail
MASTER_SITES=		http://www.dovecot.org/releases/

.if 0
PATCH_SITES=		http://www.roughtrade.net/dovecot/
PATCHFILES=		dovecot-crammd5-0.99.10.7.diff
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=		tom@replic8.net
HOMEPAGE=		http://www.dovecot.org/
COMMENT=		Secure IMAP and POP3 server

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_PKGINSTALL= 	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-ssldir=${SSLCERTS}

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		DOVECOT_USE_GNUTLS DOVECOT_USE_MYSQL \
			DOVECOT_USE_PGSQL USE_INET6 USE_OPENLDAP USE_SASL2

.if !empty(DOVECOT_USE_GNUTLS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ssl=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --enable-ssl=openssl
.  include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(DOVECOT_USE_MYSQL:M[Yy][Ee][SS])
CONFIGURE_ARGS+=	--with-mysql
.  include "../../databases/mysql4-client/buildlink3.mk"
.endif

.if !empty(DOVECOT_USE_PGSQL:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-pgsql
CPPFLAGS=		-I${BUILDLINK_DIR}/include/pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.endif

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(USE_OPENLDAP:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap/buildlink3.mk"
.endif

.if defined(USE_SASL2) && !empty(USE_SASL2:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-cyrus-sasl2
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif

RCD_SCRIPTS=	dovecot

DOVECOT_USER?=	dovecot
DOVECOT_GROUP?=	dovecot
PKG_GROUPS=	${DOVECOT_GROUP}
PKG_USERS=	${DOVECOT_USER}:${DOVECOT_GROUP}::Dovecot\\ IMAP/POP3\\ user

EGDIR=		${PREFIX}/share/examples/dovecot
CONF_FILES=	${EGDIR}/dovecot.conf.default ${PKG_SYSCONFDIR}/dovecot.conf

INSTALLATION_DIRS=	libexec/dovecot sbin share/doc/dovecot share/examples/dovecot

post-configure:
	@cd ${WRKSRC};							\
	for i in dovecot-example.conf; do				\
		${SED} ${FILES_SUBST_SED} $$i > $$i.new;		\
		${MV} -f $$i.new $$i;					\
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf	\
		${EGDIR}/dovecot.conf.default
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-* ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${EGDIR}

.include "../../mk/bsd.pkg.mk"
