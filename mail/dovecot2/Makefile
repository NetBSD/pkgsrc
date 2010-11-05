# $NetBSD: Makefile,v 1.1.1.1 2010/11/05 12:00:39 adam Exp $

DISTNAME=	dovecot-2.0.6
CATEGORIES=	mail
MASTER_SITES=	http://www.dovecot.org/releases/2.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dovecot.org/
COMMENT=	Secure IMAP and POP3 server
LICENSE=	mit AND gnu-lgpl-v2.1 AND modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config rpcgen
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ssldir=${SSLDIR}

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=		dovecot

DOVECOT_USER?=		dovecot
DOVECOT_GROUP?=		dovecot
PKG_GROUPS=		${DOVECOT_GROUP}
PKG_USERS=		${DOVECOT_USER}:${DOVECOT_GROUP}
PKG_GROUPS_VARS+=	DOVECOT_GROUP
PKG_USERS_VARS=		DOVECOT_USER

PKG_GECOS.${DOVECOT_USER}=	Dovecot IMAP/POP3 user

SUBST_CLASSES+=		ssldir
SUBST_MESSAGE.ssldir=	Fixing SSLDIR
SUBST_FILES.ssldir=	doc/example-config/conf.d/10-ssl.conf
SUBST_STAGE.ssldir=	pre-configure
SUBST_SED.ssldir=	-e 's,/etc/ssl,${SSLDIR},'

EGDIR=		${PREFIX}/share/examples/dovecot
CONFD=		${PKG_SYSCONFDIR}/dovecot/conf.d
MAKE_DIRS+=	${CONFD}
CONF_FILES+=	${EGDIR}/dovecot.conf ${PKG_SYSCONFDIR}/dovecot/dovecot.conf
CONF_FILES+=	${EGDIR}/dovecot-db.conf.ext ${PKG_SYSCONFDIR}/dovecot/dovecot-db.conf.ext
CONF_FILES+=	${EGDIR}/dovecot-dict-sql.conf.ext ${PKG_SYSCONFDIR}/dovecot/dovecot-dict-sql.conf.ext
CONF_FILES+=	${EGDIR}/dovecot-ldap.conf.ext ${PKG_SYSCONFDIR}/dovecot/dovecot-ldap.conf.ext
CONF_FILES+=	${EGDIR}/dovecot-sql.conf.ext ${PKG_SYSCONFDIR}/dovecot/dovecot-sql.conf.ext
CONF_FILES+=	${EGDIR}/conf.d/10-auth.conf ${CONFD}/10-auth.conf
CONF_FILES+=	${EGDIR}/conf.d/10-director.conf ${CONFD}/10-director.conf
CONF_FILES+=	${EGDIR}/conf.d/10-logging.conf ${CONFD}/10-logging.conf
CONF_FILES+=	${EGDIR}/conf.d/10-mail.conf ${CONFD}/10-mail.conf
CONF_FILES+=	${EGDIR}/conf.d/10-master.conf ${CONFD}/10-master.conf
CONF_FILES+=	${EGDIR}/conf.d/10-ssl.conf ${CONFD}/10-ssl.conf
CONF_FILES+=	${EGDIR}/conf.d/15-lda.conf ${CONFD}/15-lda.conf
CONF_FILES+=	${EGDIR}/conf.d/20-imap.conf ${CONFD}/20-imap.conf
CONF_FILES+=	${EGDIR}/conf.d/20-lmtp.conf ${CONFD}/20-lmtp.conf
CONF_FILES+=	${EGDIR}/conf.d/20-pop3.conf ${CONFD}/20-pop3.conf
CONF_FILES+=	${EGDIR}/conf.d/90-acl.conf ${CONFD}/90-acl.conf
CONF_FILES+=	${EGDIR}/conf.d/90-plugin.conf ${CONFD}/90-plugin.conf
CONF_FILES+=	${EGDIR}/conf.d/90-quota.conf ${CONFD}/90-quota.conf
CONF_FILES+=	${EGDIR}/conf.d/auth-checkpassword.conf.ext ${CONFD}/auth-checkpassword.conf.ext
CONF_FILES+=	${EGDIR}/conf.d/auth-deny.conf.ext ${CONFD}/auth-deny.conf.ext
CONF_FILES+=	${EGDIR}/conf.d/auth-ldap.conf.ext ${CONFD}/auth-ldap.conf.ext
CONF_FILES+=	${EGDIR}/conf.d/auth-master.conf.ext ${CONFD}/auth-master.conf.ext
CONF_FILES+=	${EGDIR}/conf.d/auth-passwdfile.conf.ext ${CONFD}/auth-passwdfile.conf.ext
CONF_FILES+=	${EGDIR}/conf.d/auth-sql.conf.ext ${CONFD}/auth-sql.conf.ext
CONF_FILES+=	${EGDIR}/conf.d/auth-static.conf.ext ${CONFD}/auth-static.conf.ext
CONF_FILES+=	${EGDIR}/conf.d/auth-system.conf.ext ${CONFD}/auth-system.conf.ext
CONF_FILES+=	${EGDIR}/conf.d/auth-vpopmail.conf.ext ${CONFD}/auth-vpopmail.conf.ext

INSTALLATION_DIRS=	libexec/dovecot sbin share/doc/dovecot
INSTALLATION_DIRS+=	share/examples/dovecot share/examples/dovecot/conf.d

BUILD_DEFS+=		VARBASE

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
