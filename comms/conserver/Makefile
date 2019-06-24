# $NetBSD: Makefile,v 1.32 2019/06/24 10:59:41 nia Exp $
#

DISTNAME=	conserver-7.2.7
PKGREVISION=	5
CATEGORIES=	comms
MASTER_SITES=	http://www.conserver.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.conserver.com/
COMMENT=	Application that allows multiple users to watch serial consoles

GNU_CONFIGURE=	YES
CONFLICTS+=	conserver8-[0-9]*

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-master=${CONSERVER_DEFAULTHOST:Q}
CONFIGURE_ARGS+=	--with-port=${CONSERVER_DEFAULTPORT:Q}
CONFIGURE_ARGS+=	--with-regex
CONFIGURE_ARGS+=	--with-libwrap
CONFIGURE_ARGS+=	--with-logfile=${VARBASE}/log/conserver

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == alpha || ${MACHINE_ARCH} == sparc64 || \
	${MACHINE_ARCH} == x86_64
CONFIGURE_ARGS+=	--with-64bit
.endif

BUILD_DEFS+=	VARBASE CONSERVER_DEFAULTPORT CONSERVER_DEFAULTHOST

RCD_SCRIPTS=	conserver

TEST_TARGET=	test

EGDIR=		${PREFIX}/share/examples/conserver
CONF_FILES=	${EGDIR}/conserver.cf.example ${PKG_SYSCONFDIR}/conserver.cf
CONF_FILES+=	${EGDIR}/conserver.passwd.example ${PKG_SYSCONFDIR}/conserver.passwd
OWN_DIRS=	${VARBASE}/consoles

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	conserver.cf/conserver.cf
SUBST_SED.conf=		-e s,/var/consoles,${VARBASE}/consoles,

INSTALLATION_DIRS+=	${EGDIR}

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
