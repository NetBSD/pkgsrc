# $NetBSD: Makefile,v 1.5 2004/01/22 07:24:25 grant Exp $
#

DISTNAME=	goofey-3.15
CATEGORIES=	chat
MASTER_SITES=	http://redback.spyda.net/~grant/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~tym/goofey.html
COMMENT=	Text-based client for goofey, a flexible short message system

NO_CONFIGURE=	# defined
LDFLAGS.SunOS=	-lnsl -lsocket

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${LDFLAGS} -o goofey goofey.c

do-install:
	${INSTALL} ${WRKSRC}/goofey ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/goofey.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"

