# $NetBSD: Makefile,v 1.16 2009/06/30 00:07:13 joerg Exp $
#

DISTNAME=		portlib-1.01
PKGNAME=		libportlib-1.01
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/portlib/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Portable file locking and directory reading

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/portlib-1.01
INSTALLATION_DIRS=	include lib

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|'

do-install:
	${INSTALL_DATA} ${WRKSRC}/libport.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/portlib.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
