# $NetBSD: Makefile,v 1.13 2014/02/12 23:18:27 tron Exp $

DISTNAME=	unworkable-0.53
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://unworkable.googlecode.com/files/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://code.google.com/p/unworkable/
COMMENT=	BSD-licensed command-line torrent client
LICENSE=	isc

USE_TOOLS+=	yacc
WRKSRC=		${WRKDIR}/unworkable
MAKE_FILE=	BSDmakefile

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

post-configure:
	cp ${WRKSRC}/openbsd-compat/sha1.c ${WRKSRC}
	cp ${WRKSRC}/openbsd-compat/strtonum.c ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unworkable ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unworkable.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
