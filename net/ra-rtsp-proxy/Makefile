# $NetBSD: Makefile,v 1.29 2016/02/25 16:20:52 jperkin Exp $

DISTNAME=	rtspd-src-1.0.0.0
PKGNAME=	ra-rtsp-proxy-1.0.0.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.scn.rain.com/pub/security/firewalls/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://service.real.com/firewall/fdev.html
COMMENT=	Proxy server for the RealAudio RTSP protocol
LICENSE=	no-commercial-use

RESTRICTED=		${LICENSE}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

RCD_SCRIPTS=		rtspd

WRKSRC=		${WRKDIR}/rtspd-1.0.0.0a

MAKE_ENV.SunOS+=	LOCAL_LIBS="-lsocket -lnsl"

INSTALLATION_DIRS=	etc/rc.d ${PKGMANDIR}/man8 sbin share/doc/ra-rtsp-proxy

do-install:
	${INSTALL_MAN} ${WRKSRC}/rtspd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_PROGRAM} ${WRKSRC}/rtspd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DESTDIR}${PREFIX}/share/doc/ra-rtsp-proxy
	@${SED} -e 's#/usr/local#${PREFIX}#g' <${WRKSRC}/README \
	  >${DESTDIR}${PREFIX}/share/doc/ra-rtsp-proxy/README

.include "../../mk/bsd.pkg.mk"
