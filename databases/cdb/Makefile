# $NetBSD: Makefile,v 1.13 2004/12/03 15:14:53 wiz Exp $

DISTNAME=	cdb-0.75
CATEGORIES=	databases
MASTER_SITES=	http://cr.yp.to/cdb/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cr.yp.to/cdb.html
COMMENT=	Creates and reads constant databases

RESTRICTED=	"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes

BUILD_TARGET=	it
INSTALL_TARGET=	setup check

INSTALLATION_DIRS=	bin include lib

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

post-install:
	${INSTALL_DATA} ${WRKSRC}/cdb.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/cdb.a ${PREFIX}/lib/libcdb.a

.include "../../mk/bsd.pkg.mk"
