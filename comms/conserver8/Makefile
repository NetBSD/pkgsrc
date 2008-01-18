# $NetBSD: Makefile,v 1.7 2008/01/18 05:06:25 tnn Exp $
#

DISTNAME=	conserver-8.1.16
PKGNAME=	conserver8-8.1.16
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.conserver.com/conserver/

MAINTAINER=	awrede@users.sourceforge.net
HOMEPAGE=	http://www.conserver.com/
COMMENT=	Application that allows multiple users to watch serial consoles

CONFLICTS=	conserver-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-master=${CONSERVER_DEFAULTHOST:Q}
CONFIGURE_ARGS+=	--with-port=${CONSERVER_DEFAULTPORT:Q}
CONFIGURE_ARGS+=	--with-regex
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ARGS+=	--with-logfile=${VARBASE:Q}/log/conserver

PKG_OPTIONS_VAR=	PKG_OPTIONS.conserver8
PKG_SUPPORTED_OPTIONS=	pam ssl uds
PKG_SUGGESTED_OPTIONS=	ssl
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif

.if !empty(PKG_OPTIONS:Muds)
CONFIGURE_ARGS+=	--with-uds
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
. include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
BUILD_DEFS+=	CONSERVER_DEFAULTPORT CONSERVER_DEFAULTHOST

RCD_SCRIPTS=	conserver8

TEST_TARGET=	test

DOCDIR=		${PREFIX}/share/doc/conserver
EGDIR=		${PREFIX}/share/examples/conserver
CONF_FILES=	${EGDIR}/conserver.cf ${PKG_SYSCONFDIR}/conserver.cf
CONF_FILES+=	${EGDIR}/conserver.passwd ${PKG_SYSCONFDIR}/conserver.passwd
OWN_DIRS=	${VARBASE}/consoles

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	conserver.cf/conserver.cf
SUBST_SED.conf=		-e s,/var/consoles,${VARBASE}/consoles,

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	set -e; for File in INSTALL README PROTOCOL; do			\
		${INSTALL_DATA} ${WRKSRC}/$${File} ${DOCDIR}/$${File};	\
	done

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
