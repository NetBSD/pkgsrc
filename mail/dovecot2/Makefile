# $NetBSD: Makefile,v 1.3 2010/11/09 15:35:47 ghen Exp $

DOVECOT_VERSION=	2.0
DOVECOT_SUBVERSION=	.7
SIEVE_VERSION=		0.2.1
DISTNAME=		dovecot-${DOVECOT_VERSION}${DOVECOT_SUBVERSION}
CATEGORIES=		mail
MASTER_SITES=		http://www.dovecot.org/releases/${DOVECOT_VERSION}/
DOVECOT_SIEVE_SITES=	http://www.rename-it.nl/dovecot/${DOVECOT_VERSION}/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.dovecot.org/
COMMENT=		Secure IMAP and POP3 server
LICENSE=		mit AND gnu-lgpl-v2.1 AND modified-bsd

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

SUBST_CLASSES+=		egdir
SUBST_MESSAGE.egdir=	Fixing EGDIR
# sieve adds another file here (in options.mk)
SUBST_FILES.egdir=	doc/example-config/Makefile.in
SUBST_FILES.egdir+=	doc/example-config/conf.d/Makefile.in
SUBST_FILES.egdir+=	src/config/Makefile.in
SUBST_STAGE.egdir=	pre-configure
SUBST_SED.egdir=	-e 's,^exampledir = .*/example-config,exampledir = ${PREFIX}/share/examples/dovecot,'

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

.include "options.mk"

post-build:
.if !empty(PKG_OPTIONS:Mdovecot-sieve)
# We need dovecot built in order to be able to configure sieve.
	cd ${WRKSRC.sieve} \
	&& env ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} ${CONFIGURE_ARGS.sieve}
	cd ${WRKSRC.sieve} \
	&& env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} -f ${MAKE_FILE} ${BUILD_TARGET}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${DESTDIR}${EGDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
