# $NetBSD: Makefile,v 1.12 2004/03/13 17:16:13 kristerw Exp $
#

DISTNAME=      conserver-7.2.7
CATEGORIES=    comms
MASTER_SITES=  ftp://ftp.conserver.com/conserver/

MAINTAINER=    tech-pkg@NetBSD.org
HOMEPAGE=      http://www.conserver.com/
COMMENT=       Application that allows multiple users to watch serial consoles

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-master=${DEFAULTHOST}
CONFIGURE_ARGS+=	--with-port=${DEFAULTPORT}
CONFIGURE_ARGS+=	--with-regex
CONFIGURE_ARGS+=	--with-libwrap

.if ${MACHINE_ARCH} == alpha || ${MACHINE_ARCH} == sparc64 || \
	${MACHINE_ARCH} == x86_64
CONFIGURE_ARGS+=	--with-64bit
.endif

DEFAULTPORT?=	782
DEFAULTHOST?=	localhost
RCD_SCRIPTS=	conserver

TEST_TARGET=	test

EGDIR=		${PREFIX}/share/examples/conserver
CONF_FILES=	${EGDIR}/conserver.cf.example ${PKG_SYSCONFDIR}/conserver.cf
CONF_FILES+=	${EGDIR}/conserver.passwd.example ${PKG_SYSCONFDIR}/conserver.passwd
OWN_DIRS=	/var/consoles

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
