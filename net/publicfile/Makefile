# $NetBSD: Makefile,v 1.3.2.1 2002/06/23 18:56:44 jlam Exp $
#

DISTNAME=		publicfile-0.52
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/publicfile/

MAINTAINER=		zuntum@netbsd.org
HOMEPAGE=		http://cr.yp.to/publicfile.html
COMMENT=		secure read-only HTTP and FTP servers

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

ALL_TARGET=		it
INSTALL_TARGET=		setup check

RESTRICTED=		"unsure of djb's license"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

pre-build:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX}/publicfile > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
