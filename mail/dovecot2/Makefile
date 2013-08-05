# $NetBSD: Makefile,v 1.48 2013/08/05 23:12:42 bouyer Exp $

DISTNAME=	dovecot-2.2.4
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.dovecot.org/releases/2.2/
PKGREVISION=	1

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.dovecot.org/
COMMENT=	Secure IMAP and POP3 server
LICENSE=	mit AND gnu-lgpl-v2.1 AND modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config rpcgen
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ssldir=${SSLDIR}

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=		dovecot

DOVECOT_USER?=		dovecot
DOVECOT_GROUP?=		dovecot
DOVENULL_USER?=		dovenull
DOVENULL_GROUP?=	dovenull
PKG_GROUPS=		${DOVECOT_GROUP} ${DOVENULL_GROUP}
PKG_USERS=		${DOVECOT_USER}:${DOVECOT_GROUP}	\
			${DOVENULL_USER}:${DOVENULL_GROUP}
PKG_GROUPS_VARS=	DOVECOT_GROUP DOVENULL_GROUP
PKG_USERS_VARS=		DOVECOT_USER DOVENULL_USER

PKG_GECOS.${DOVECOT_USER}=	Dovecot IMAP/POP3 user
PKG_GECOS.${DOVENULL_USER}=	Dovecot login user

SUBST_CLASSES+=		ssldir
SUBST_MESSAGE.ssldir=	Fixing SSLDIR
SUBST_FILES.ssldir=	doc/example-config/conf.d/10-ssl.conf
SUBST_STAGE.ssldir=	pre-configure
SUBST_SED.ssldir=	-e 's,/etc/ssl,${SSLDIR},'

EGDIR=			${PREFIX}/share/examples/dovecot

CNFS_cmd=		${SED} -ne "s,^share/examples/dovecot/,,p" PLIST
CNFS=			${CNFS_cmd:sh}
CONF_FILES=		${EGDIR}/dovecot.conf ${PKG_SYSCONFDIR}/dovecot/dovecot-example.conf
.for file in ${CNFS}
CONF_FILES+=		${EGDIR}/${file:Q} ${PKG_SYSCONFDIR}/dovecot/${file:Q}
.endfor

INSTALLATION_DIRS=	libexec/dovecot sbin share/doc/dovecot
INSTALLATION_DIRS+=	share/examples/dovecot share/examples/dovecot/conf.d
OWN_DIRS=		${PKG_SYSCONFDIR}/dovecot/
OWN_DIRS+=		${PKG_SYSCONFDIR}/dovecot/conf.d

BUILD_DEFS+=		VARBASE

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${DESTDIR}${EGDIR}

.include "options.mk"

# Don't compress manual pages as they include each other.
.undef MANZ

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
