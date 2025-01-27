# $NetBSD: Makefile,v 1.30 2025/01/27 14:07:32 wiz Exp $

DISTNAME=	rtspd-src-1.0.0.0
PKGNAME=	ra-rtsp-proxy-1.0.0.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.mirrorservice.org/pub/minix/distfiles/backup/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://service.real.com/firewall/fdev.html
COMMENT=	Proxy server for the RealAudio RTSP protocol
LICENSE=	no-commercial-use

RESTRICTED=		${LICENSE}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

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
