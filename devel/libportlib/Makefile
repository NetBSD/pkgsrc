# $NetBSD: Makefile,v 1.8 2003/12/13 16:20:09 ben Exp $
#

DISTNAME=		portlib-1.01
PKGNAME=		libportlib-1.01
WRKSRC=			${WRKDIR}/portlib-1.01
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/portlib/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Portable file locking and directory reading

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|'

do-install:
	${INSTALL_DATA} ${WRKSRC}/libport.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/portlib.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
