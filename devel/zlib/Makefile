# $NetBSD: Makefile,v 1.2 1999/09/20 23:23:57 kim Exp $
#

DISTNAME=	zlib-1.1.3
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.cdrom.com/pub/infozip/zlib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cdrom.com/pub/infozip/zlib/

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --shared

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/lib/libz.a)
IGNORE=		"is part of your NetBSD distribution"
.endif

CFLAGS=		-fPIC -O3

post-extract:
	@cd ${WRKDIR} && ${MKDIR} static && ${PAX} -rw ${DISTNAME} static

post-patch:
	@${MAKE} do-patch WRKSRC=${WRKDIR}/static/${DISTNAME}

post-configure:
	@${MAKE} do-configure WRKSRC=${WRKDIR}/static/${DISTNAME} CFLAGS=-O3 \
	CONFIGURE_ARGS="`${ECHO} ${CONFIGURE_ARGS} | ${SED} -e 's/--shared//'`"

post-build:
	@${MAKE} do-build WRKSRC=${WRKDIR}/static/${DISTNAME} CFLAGS=-O3

post-install:
	${INSTALL_DATA} ${WRKDIR}/static/${DISTNAME}/libz.a ${PREFIX}/lib
	cd ${PREFIX}/lib && ranlib libz.a

.include "../../mk/bsd.pkg.mk"
