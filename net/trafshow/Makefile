# $NetBSD: Makefile,v 1.6 2001/02/17 18:19:47 wiz Exp $
# $FreeBSD: ports/net/trafshow/Makefile,v 1.14 2000/06/28 12:53:15 alex Exp $
#

DISTNAME=	trafshow-3.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nsk.su/pub/RinetSoftware/
EXTRACT_SUFX=	.tgz

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://soft.risp.ru/trafshow/index.shtml
COMMENT=	Full screen visualization of the network traffic

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoreconf:../../devel/autoconf

GNU_CONFIGURE=	yes
ALL_TARGET=	trafshow

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/examples/trafshow
	${INSTALL_DATA} ${WRKSRC}/.trafshow \
		${PREFIX}/share/examples/trafshow/trafshow

.include "../../mk/bsd.pkg.mk"
