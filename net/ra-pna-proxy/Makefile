# $NetBSD: Makefile,v 1.1.1.1 1999/09/01 19:44:03 tron Exp $

DISTNAME=	raproxy3.0b1
PKGNAME=	ra-pna-proxy-3.0b1
CATEGORIES=	net
MASTER_SITES=	# empty

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://service.real.com/firewall/fdev.html

LICENSE=		no-commercial-use
MIRROR_DISTFILE=	no

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

.include "../../mk/bsd.pkg.mk"
