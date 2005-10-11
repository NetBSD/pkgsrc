# $NetBSD: Makefile,v 1.22 2005/10/11 17:02:50 reed Exp $

DISTNAME=	trafshow-5.2.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nsk.su/pub/RinetSoftware/
EXTRACT_SUFX=	.tgz

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://soft.risp.ru/trafshow/index.shtml
COMMENT=	Full screen visualization of the network traffic

BUILD_TARGET=	trafshow
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CPPFLAGS+=	-DINET6
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/trafshow

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/.trafshow \
		${PREFIX}/share/examples/trafshow/trafshow

BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.7
.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
