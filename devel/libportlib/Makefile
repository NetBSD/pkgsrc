# $NetBSD: Makefile,v 1.12 2005/06/16 06:57:47 jlam Exp $
#

DISTNAME=		portlib-1.01
PKGNAME=		libportlib-1.01
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/portlib/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Portable file locking and directory reading

WRKSRC=			${WRKDIR}/portlib-1.01
INSTALLATION_DIRS=	include lib

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|'

do-install:
	${INSTALL_DATA} ${WRKSRC}/libport.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/portlib.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
