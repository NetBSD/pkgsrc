# $NetBSD: Makefile,v 1.6 2004/07/22 01:10:40 schmonz Exp $
#

DISTNAME=	checkpassword-0.90
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/checkpwd/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cr.yp.to/checkpwd.html
COMMENT=	Simple, uniform password-checking interface to all root applications

RESTRICTED=	"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

USE_BUILDLINK3=	yes

ALL_TARGET=	it
INSTALL_TARGET=	setup check

do-configure:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld

.include "../../mk/bsd.pkg.mk"
