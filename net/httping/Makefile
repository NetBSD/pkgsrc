# $NetBSD: Makefile,v 1.11 2009/07/17 18:00:19 adrianp Exp $
#

DISTNAME=		httping-1.2.9
CATEGORIES=		net
MASTER_SITES=		http://www.vanheusden.com/httping/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.vanheusden.com/httping/
COMMENT=		Like 'ping' but for http-requests

.include "../../mk/bsd.prefs.mk"

LDFLAGS.SunOS=		-lnsl -lsocket

.if (${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[123]*)) || \
    ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
.else
CFLAGS+=	-DHAVE_STRNDUP
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/httping.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/httping ${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
