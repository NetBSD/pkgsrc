# $NetBSD: Makefile,v 1.16 2016/09/11 12:46:46 mef Exp $
#

DISTNAME=	6tunnel-0.11
CATEGORIES=	net
MASTER_SITES=	http://toxygen.net/6tunnel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://toxygen.net/6tunnel/
COMMENT=	Tunnelling for applications that don't speak IPv6
LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM+= Interix-*-* # no IPv6 support

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/6tunnel ${WRKSRC}/6tunnel.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/6tunnel ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/6tunnel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
