# $NetBSD: Makefile,v 1.11 2004/01/05 12:05:54 jlam Exp $
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

DEFAULTPORT?=	782
DEFAULTHOST?=	localhost
RCD_SCRIPTS=	conserver

TEST_TARGET=	test

EGDIR=		${PREFIX}/share/examples/conserver
CONF_FILES=	${EGDIR}/conserver.cf.example ${PKG_SYSCONFDIR}/conserver.cf
CONF_FILES+=	${EGDIR}/conserver.passwd.example ${PKG_SYSCONFDIR}/conserver.passwd
OWN_DIRS=	/var/consoles

NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
