# $NetBSD: Makefile,v 1.16 2001/11/29 01:12:44 hubertf Exp $

DISTNAME=	rtspd-src-1.0.0.0
PKGNAME=	ra-rtsp-proxy-1.0.0.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://docs.real.com/docs/proxykit/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://service.real.com/firewall/fdev.html
COMMENT=	Proxy server for the RealAudio RTSP protocol

LICENSE=		no-commercial-use
RESTRICTED=		${LICENSE}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DOWNLOAD=	http://proforma.real.com/rn/misc/rtspproxy/index.html

WRKSRC=		${WRKDIR}/rtspd-1.0.0.0a

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	LOCAL_LIBS="-lsocket -lnsl"
.endif

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
