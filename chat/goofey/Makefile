# $NetBSD: Makefile,v 1.4 2003/07/21 16:34:31 martti Exp $
#

DISTNAME=	goofey-3.15
CATEGORIES=	chat
MASTER_SITES=	http://redback.spyda.net/~grant/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~tym/goofey.html
COMMENT=	Text-based client for goofey, a flexible short message system

NO_CONFIGURE=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lnsl -lsocket
.endif

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${LDFLAGS} -o goofey goofey.c

do-install:
	${INSTALL} ${WRKSRC}/goofey ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/goofey.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"

