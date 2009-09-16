# $NetBSD: Makefile,v 1.135.2.1 2009/09/16 10:48:30 tron Exp $

DISTNAME=		dovecot-1.1.19
CATEGORIES=		mail
MASTER_SITES=		http://www.dovecot.org/releases/1.1/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.dovecot.org/
COMMENT=		Secure IMAP and POP3 server

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_TOOLS+=		rpcgen

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-ssldir=${SSLDIR:Q}
CONFIGURE_ARGS+=	--enable-header-install

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

RCD_SCRIPTS=		dovecot

DOVECOT_USER?=		dovecot
DOVECOT_GROUP?=		dovecot
PKG_GROUPS=		${DOVECOT_GROUP}
PKG_USERS=		${DOVECOT_USER}:${DOVECOT_GROUP}
PKG_GROUPS_VARS+=	DOVECOT_GROUP
PKG_USERS_VARS+=	DOVECOT_USER

PKG_GECOS.${DOVECOT_USER}=	Dovecot IMAP/POP3 user

EGDIR=			${PREFIX}/share/examples/dovecot
CONF_FILES=		${EGDIR}/dovecot-example.conf ${PKG_SYSCONFDIR}/dovecot.conf

INSTALLATION_DIRS=	libexec/dovecot sbin share/doc/dovecot		\
			share/examples/dovecot

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	dovecot-example.conf
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	pre-configure

BUILD_DEFS+=		VARBASE

post-build:
	${SED} "s|/etc/ssl/|${SSLDIR}/|" ${WRKSRC}/dovecot-example.conf \
						> ${WRKDIR}/dovecot-example.conf
	${SED} "s|/etc/ssl|${SSLDIR}|" ${WRKSRC}/doc/mkcert.sh \
						> ${WRKDIR}/mkcert.sh

post-install:
	${INSTALL_DATA} ${WRKDIR}/dovecot-example.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-* ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/mkcert.sh ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/src/lib/liblib.a ${DESTDIR}${PREFIX}/lib/dovecot

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
