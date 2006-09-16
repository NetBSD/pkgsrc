# $NetBSD: Makefile,v 1.2 2006/09/16 10:07:55 rillig Exp $
#

DISTNAME=		httping-1.2.1
CATEGORIES=		net
MASTER_SITES=		http://www.vanheusden.com/httping/
EXTRACT_SUFX=		.tgz

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://www.vanheusden.com/httping/
COMMENT=		Like 'ping' but for http-requests

LDFLAGS.SunOS=		-lnsl -lsocket

do-install:
	${INSTALL_MAN} ${WRKSRC}/httping.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/httping ${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
