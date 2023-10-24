# $NetBSD: Makefile,v 1.18 2023/10/24 22:10:36 wiz Exp $

DISTNAME=	unworkable-0.53
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://unworkable.googlecode.com/files/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/niallo/Unworkable
COMMENT=	BSD-licensed command-line torrent client
LICENSE=	isc

USE_TOOLS+=	yacc nroff
WRKSRC=		${WRKDIR}/unworkable
MAKE_FILE=	BSDmakefile

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t
LDFLAGS.SunOS+=		-lsocket -lnsl

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
