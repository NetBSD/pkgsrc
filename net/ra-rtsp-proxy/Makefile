# $NetBSD: Makefile,v 1.13 2001/05/10 05:35:01 tron Exp $

DISTNAME=	rtspd-src-1.0.0.0
PKGNAME=	ra-rtsp-proxy-1.0.0.0nb1
CATEGORIES=	net
MASTER_SITES=	# empty

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://service.real.com/firewall/fdev.html
COMMENT=	Proxy server for the RealAudio RTSP protocol

IS_INTERACTIVE=	yes

LICENSE=		no-commercial-use
RESTRICTED=		${LICENSE}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DOWNLOAD=	http://proforma.real.com/rn/misc/rtspproxy/index.html

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

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rtspd.sh ${PREFIX}/etc/rc.d/rtspd
	${INSTALL_MAN} ${WRKSRC}/rtspd.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/rtspd ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ra-rtsp-proxy
	${INSTALL_DATA} ${WRKSRC}/license.txt ${PREFIX}/share/doc/ra-rtsp-proxy
	@${SED} -e 's#/usr/local#${PREFIX}#g' <${WRKSRC}/README \
	  >${PREFIX}/share/doc/ra-rtsp-proxy/README

.include "../../mk/bsd.pkg.mk"
