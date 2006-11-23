# $NetBSD: Makefile,v 1.67.2.1 2006/11/23 19:56:43 salo Exp $

DISTNAME=		dovecot-1.0.rc7
PKGNAME=		${DISTNAME:S/.rc/rc/}
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://www.dovecot.org/releases/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.dovecot.org/
COMMENT=		Secure IMAP and POP3 server

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-ssldir=${SSLDIR:Q}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

RCD_SCRIPTS=		dovecot

DOVECOT_USER?=		dovecot
DOVECOT_GROUP?=		dovecot
PKG_GROUPS=		${DOVECOT_GROUP}
PKG_USERS=		${DOVECOT_USER}:${DOVECOT_GROUP}

PKG_GECOS.${DOVECOT_USER}=	Dovecot IMAP/POP3 user

EGDIR=			${PREFIX}/share/examples/dovecot
CONF_FILES=		${EGDIR}/dovecot.conf.default ${PKG_SYSCONFDIR}/dovecot.conf

INSTALLATION_DIRS=	libexec/dovecot sbin share/doc/dovecot		\
			share/examples/dovecot

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	dovecot-example.conf
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	pre-configure

post-build:
	${SED} "s|/etc/ssl/|${SSLDIR}/|" ${WRKSRC}/dovecot-example.conf \
						> ${WRKDIR}/dovecot-example.conf
	${SED} "s|/etc/ssl|${SSLDIR}|" ${WRKSRC}/doc/mkcert.sh \
						> ${WRKDIR}/mkcert.sh

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/dovecot-example.conf	\
		${EGDIR}/dovecot.conf.default
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-* ${EGDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/mkcert.sh ${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
