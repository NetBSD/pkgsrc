# $NetBSD: Makefile,v 1.6 2003/02/05 15:50:10 dmcmahill Exp $
# FreeBSD Id: ports/comms/conserver-com/Makefile,v 1.1 2001/12/09 14:40:12 kur iyama Exp

DISTNAME=      conserver-7.2.1
CATEGORIES=    comms
MASTER_SITES=  ftp://ftp.conserver.com/conserver/

MAINTAINER=    packages@netbsd.org
HOMEPAGE=      http://www.conserver.com/
COMMENT=       Application that allows multiple users to watch serial consoles

USE_BUILDLINK2=		YES
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

EGDIR=		${PREFIX}/share/examples/conserver
CONF_FILES=	${EGDIR}/conserver.cf.example ${PKG_SYSCONFDIR}/conserver.cf
CONF_FILES+=	${EGDIR}/conserver.passwd.example ${PKG_SYSCONFDIR}/conserver.passwd
OWN_DIRS=	/var/consoles

NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
