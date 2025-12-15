# $NetBSD: Makefile,v 1.21 2025/12/15 21:29:34 wiz Exp $

DISTNAME=		MemMgr-1.04
PKGNAME=		libmemmgr-1.04
CATEGORIES=		devel
MASTER_SITES=		https://www.aydogan.net/distfiles/devel/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		${MASTER_SITES}
COMMENT=		Simple memory manager library

WRKSRC=			${WRKDIR}/memmgr-1.04
INSTALLATION_DIRS=	include lib
USE_TOOLS+=		groff

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing absolute paths.
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|'

INSTALLATION_DIRS+=	share/doc/libmemmgr

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmemmgr.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/memmgr.h ${DESTDIR}${PREFIX}/include
	${TOOLS_PATH.groff} -Tascii -ms ${WRKSRC}/memmgr.ms \
		>${DESTDIR}${PREFIX}/share/doc/libmemmgr/memmgr.txt

.include "../../devel/libetm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
