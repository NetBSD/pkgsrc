# $NetBSD: Makefile,v 1.1.1.1 1999/09/01 20:25:02 tron Exp $

DISTNAME=	rtspd-src-1.0.0.0
PKGNAME=	ra-rtsp-proxy-1.0.0.0
CATEGORIES=	net
MASTER_SITES=	# empty

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://service.real.com/firewall/fdev.html

LICENSE=		no-commercial-use
MIRROR_DISTFILE=	no

DOWNLOAD=	http://proforma.real.com/mario/devzone/rtspproxyform.html

MESSAGE_FILE=	${WRKDIR}/MESSAGE
WRKSRC=		${WRKDIR}/rtspd-1.0.0.0a

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	    ${ECHO_MSG} "==============================================================="; \
	    ${ECHO_MSG} "  The RTSP Proxy Kit must be fetched into \"${DISTDIR}\""; \
	    ${ECHO_MSG} "  via the Web formular available under this URL:"; \
	    ${ECHO_MSG} "  ${DOWNLOAD}"; \
	    ${ECHO_MSG} "==============================================================="; \
	    ${FALSE}; \
	fi

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/rtspd.sh >${WRKDIR}/rtspd.sh
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/MESSAGE \
	  >${MESSAGE_FILE}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rtspd.sh ${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/rtspd.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/rtspd ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/share/doc/rtspd
	${INSTALL_DATA} ${WRKSRC}/license.txt ${PREFIX}/share/doc/rtspd
	@${SED} -e 's#/usr/local#${PREFIX}#g' <${WRKSRC}/README \
	  >${PREFIX}/share/doc/rtspd/README

.include "../../mk/bsd.pkg.mk"
