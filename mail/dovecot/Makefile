# $NetBSD: Makefile,v 1.162 2012/12/16 01:52:20 obache Exp $

DOVECOT_VERSION=	1.2
DOVECOT_SUBVERSION=	.17
SIEVE_VERSION=		0.1.19
MANAGESIEVE_VERSION=	0.11.13
DISTNAME=		dovecot-${DOVECOT_VERSION}${DOVECOT_SUBVERSION}
PKGREVISION=		5
CATEGORIES=		mail
MASTER_SITES=		http://www.dovecot.org/releases/${DOVECOT_VERSION}/
DOVECOT_SIEVE_SITES=	http://www.rename-it.nl/dovecot/${DOVECOT_VERSION}/

MANAGESIEVE_PATCH=			dovecot-${DOVECOT_VERSION}${DOVECOT_SUBVERSION}-managesieve-${MANAGESIEVE_VERSION}.diff.gz
SITES.${MANAGESIEVE_PATCH}=	${DOVECOT_SIEVE_SITES}
PATCH_DIST_STRIP.${MANAGESIEVE_PATCH}=	-p1

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.dovecot.org/
COMMENT=		Secure IMAP and POP3 server
LICENSE=		mit AND gnu-lgpl-v2.1 AND modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config rpcgen
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-header-install
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ssldir=${SSLDIR}

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

EGDIR=		${PREFIX}/share/examples/dovecot
CONF_FILES=	${EGDIR}/dovecot-example.conf ${PKG_SYSCONFDIR}/dovecot.conf

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
.if !empty(PKG_OPTIONS:Mdovecot-sieve)
# We need dovecot built in order to be able to configure sieve.
	cd ${WRKSRC.sieve} \
	&& env ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} ${CONFIGURE_ARGS.sieve}
	cd ${WRKSRC.sieve} \
	&& env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} -f ${MAKE_FILE} ${BUILD_TARGET}
.endif
.if !empty(PKG_OPTIONS:Mdovecot-managesieve)
# Wee need sieve built in order to configure and build managesieve. Sigh.
	cd ${WRKSRC.managesieve} \
	&& env ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} ${CONFIGURE_ARGS.managesieve}
	cd ${WRKSRC.managesieve} \
	&& env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} -f ${MAKE_FILE} ${BUILD_TARGET}
.endif

post-install:
	${INSTALL_DATA} ${WRKDIR}/dovecot-example.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-* ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/mkcert.sh ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/src/lib/liblib.a ${DESTDIR}${PREFIX}/lib/dovecot

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
