# $NetBSD: Makefile,v 1.18 2023/12/23 08:20:52 zafer Exp $
#

DISTNAME=		portlib-1.01
PKGNAME=		libportlib-1.01
CATEGORIES=		devel
MASTER_SITES=		https://www.aydogan.net/distfiles/devel/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Portable file locking and directory reading

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
