# $NetBSD: Makefile,v 1.9 2001/05/12 11:52:54 tron Exp $

DISTNAME=	raproxy3.0b1
PKGNAME=	ra-pna-proxy-3.0b1
CATEGORIES=	net
MASTER_SITES=	http://docs.real.com/proxykit/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://service.real.com/firewall/fdev.html
COMMENT=	Proxy server for the RealAudio PNA protocol

LICENSE=		no-commercial-use
RESTRICTED=		${LICENSE}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ALL_TARGET=	raproxy
PROGNAME=	${PKGNAME:C/-[1-9].*//}
WRKSRC=		${WRKDIR}/raproxy

post-build:
	cd ${WRKSRC}; \
	${SED} -e 's#/usr/local#${PREFIX}#g' <raproxy.man >${PROGNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/raproxy ${PREFIX}/libexec/${PROGNAME}
	${INSTALL_MAN} ${WRKSRC}/${PROGNAME}.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PROGNAME}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${PREFIX}/share/doc/${PROGNAME}

.include "../../mk/bsd.pkg.mk"
