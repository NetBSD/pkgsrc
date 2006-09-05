# $NetBSD: Makefile,v 1.1.1.1 2006/09/05 18:02:42 adrianp Exp $
#

DISTNAME=		httping-1.2.1
CATEGORIES=		net
MASTER_SITES=		http://www.vanheusden.com/httping/
EXTRACT_SUFX=		.tgz

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://www.vanheusden.com/httping/
COMMENT=		Like 'ping' but for http-requests

do-install:
	${INSTALL_MAN} ${WRKSRC}/httping.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/httping ${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
