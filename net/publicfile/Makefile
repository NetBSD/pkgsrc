# $NetBSD: Makefile,v 1.1.1.1 2001/09/16 22:50:39 zuntum Exp $
#

DISTNAME=		publicfile-0.52
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/publicfile/

MAINTAINER=		zuntum@netbsd.org
HOMEPAGE=		http://cr.yp.to/publicfile.html
COMMENT=		secure read-only HTTP and FTP servers

DEPENDS+=		daemontools-*:../../sysutils/daemontools

ALL_TARGET=		it
INSTALL_TARGET=		setup check

RESTRICTED=		"unsure of djb's license"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

pre-build:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${STRIPFLAG} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX}/publicfile > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
