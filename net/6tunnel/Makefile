# $NetBSD: Makefile,v 1.13 2012/10/23 17:18:07 asau Exp $
#

DISTNAME=	6tunnel-0.11rc2
CATEGORIES=	net
MASTER_SITES=	http://toxygen.net/6tunnel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://toxygen.net/6tunnel/
COMMENT=	v4/v6 protocol translation

NOT_FOR_PLATFORM+= Interix-*-* # no IPv6 support

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/6tunnel ${WRKSRC}/6tunnel.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/6tunnel ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/6tunnel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
