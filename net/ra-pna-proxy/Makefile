# $NetBSD: Makefile,v 1.16 2005/06/17 03:50:27 jlam Exp $

DISTNAME=	raproxy3.0b1
PKGNAME=	ra-pna-proxy-3.0b1
CATEGORIES=	net
MASTER_SITES=	http://ftp.teledanmark.no/pub/networking/firewall/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://service.real.com/firewall/fdev.html
COMMENT=	Proxy server for the RealAudio PNA protocol

LICENSE=		no-commercial-use
RESTRICTED=		${LICENSE}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/raproxy
BUILD_TARGET=	raproxy
PROGNAME=	${PKGNAME:C/-[1-9].*//}

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS="${LIBS}"

INSTALLATION_DIRS=	libexec man/man8

post-build:
	cd ${WRKSRC}; \
	${SED} -e 's#/usr/local#${PREFIX}#g' <raproxy.man >${PROGNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/raproxy ${PREFIX}/libexec/${PROGNAME}
	${INSTALL_MAN} ${WRKSRC}/${PROGNAME}.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PROGNAME}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${PREFIX}/share/doc/${PROGNAME}

.include "../../mk/bsd.pkg.mk"
