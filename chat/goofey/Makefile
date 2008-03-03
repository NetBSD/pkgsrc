# $NetBSD: Makefile,v 1.10 2008/03/03 02:19:51 jlam Exp $
#

DISTNAME=	goofey-3.15
CATEGORIES=	chat
MASTER_SITES=	http://redback.spyda.net/~grant/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~tym/goofey.html
COMMENT=	Text-based client for goofey, a flexible short message system

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
LDFLAGS.SunOS+=	-lnsl -lsocket

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${LDFLAGS} -o goofey goofey.c

do-install:
	${INSTALL} ${WRKSRC}/goofey ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/goofey.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
