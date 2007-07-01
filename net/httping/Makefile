# $NetBSD: Makefile,v 1.5 2007/07/01 15:56:08 adrianp Exp $
#

DISTNAME=		httping-1.2.3
CATEGORIES=		net
MASTER_SITES=		http://www.vanheusden.com/httping/
EXTRACT_SUFX=		.tgz

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://www.vanheusden.com/httping/
COMMENT=		Like 'ping' but for http-requests

LDFLAGS.SunOS=		-lnsl -lsocket

do-install:
	${INSTALL_MAN} ${WRKSRC}/httping.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/httping ${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
