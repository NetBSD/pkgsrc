# $NetBSD: Makefile,v 1.16 2012/10/23 17:18:27 asau Exp $

DISTNAME=	httping-1.5.2
CATEGORIES=	net
MASTER_SITES=	http://www.vanheusden.com/httping/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vanheusden.com/httping/
COMMENT=	Like 'ping' but for http-requests
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

LDFLAGS.SunOS=		-lnsl -lsocket

.if (${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[123]*)) || \
    ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
.else
CFLAGS+=	-DHAVE_STRNDUP
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man1 bin

do-install:
	${INSTALL_MAN} ${WRKSRC}/httping.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/httping ${DESTDIR}${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
