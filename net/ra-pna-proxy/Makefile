# $NetBSD: Makefile,v 1.6 2001/02/17 18:19:30 wiz Exp $

DISTNAME=	raproxy3.0b1
PKGNAME=	ra-pna-proxy-3.0b1
CATEGORIES=	net
MASTER_SITES=	# empty

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://service.real.com/firewall/fdev.html
COMMENT=	Proxy server for the RealAudio PNA protocol

IS_INTERACTIVE=	yes

LICENSE=		no-commercial-use
RESTRICTED=		${LICENSE}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DOWNLOAD=	http://proforma.real.com/mario/devzone/proxyform.html

ALL_TARGET=	raproxy
PROGNAME=	${PKGNAME:C/-[1-9].*//}
WRKSRC=		${WRKDIR}/raproxy

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	    ${ECHO_MSG} "==============================================================="; \
	    ${ECHO_MSG} "  The PNA Proxy Kit must be fetched into \"${DISTDIR}\""; \
	    ${ECHO_MSG} "  via the Web formular available under this URL:"; \
	    ${ECHO_MSG} "  ${DOWNLOAD}"; \
	    ${ECHO_MSG} "==============================================================="; \
	    ${FALSE}; \
	fi

post-build:
	cd ${WRKSRC}; \
	${SED} -e 's#/usr/local#${PREFIX}#g' <raproxy.man >${PROGNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/raproxy ${PREFIX}/libexec/${PROGNAME}
	${INSTALL_MAN} ${WRKSRC}/${PROGNAME}.8 ${PREFIX}/man/man8
	${MKDIR} ${PREFIX}/share/doc/${PROGNAME}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${PREFIX}/share/doc/${PROGNAME}

.include "../../mk/bsd.pkg.mk"
