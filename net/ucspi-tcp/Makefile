# $NetBSD: Makefile,v 1.20 2004/12/03 15:15:06 wiz Exp $
# FreeBSD Id: ports/sysutils/ucspi-tcp/Makefile,v 1.12 2000/07/10 01:41:24 steve Exp

DISTNAME=	ucspi-tcp-0.88
CATEGORIES=	sysutils net
MASTER_SITES=	http://cr.yp.to/ucspi-tcp/				\
		ftp://cr.yp.to/djbdns/					\
		ftp://ftp.innominate.org/pub/pape/djb/
DISTFILES=	${DISTNAME}.tar.gz					\
		${DISTNAME}-man-20010502.tar.gz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cr.yp.to/ucspi-tcp.html
COMMENT=	Command-line tools for building TCP client-server applications

RESTRICTED=	"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes

BUILD_TARGET=	it
INSTALL_TARGET=	setup check

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	3.0
.endif

INSTALLATION_DIRS=	bin man man/man1

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

post-install:
	cd ${WRKDIR}/${DISTNAME}-man &&					\
	for i in *.1; do						\
		${INSTALL_MAN} $${i} ${PREFIX}/man/man1;		\
	done

.include "../../mk/bsd.pkg.mk"
