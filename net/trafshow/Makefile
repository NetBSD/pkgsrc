# $NetBSD: Makefile,v 1.4 2001/02/05 09:01:02 tron Exp $
# $FreeBSD: ports/net/trafshow/Makefile,v 1.14 2000/06/28 12:53:15 alex Exp $
#

DISTNAME=	trafshow-3.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nsk.su/pub/RinetSoftware/
EXTRACT_SUFX=	.tgz

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://soft.risp.ru/trafshow/index.shtml

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoremake:../../devel/autoconf

GNU_CONFIGURE=	yes
ALL_TARGET=	trafshow

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoremake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/examples/trafshow
	${INSTALL_DATA} ${WRKSRC}/.trafshow \
		${PREFIX}/share/examples/trafshow/trafshow

.include "../../mk/bsd.pkg.mk"
