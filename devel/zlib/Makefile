# $NetBSD: Makefile,v 1.1.1.1 1999/09/19 21:53:29 kim Exp $
#

DISTNAME=	zlib-1.1.3
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.cdrom.com/pub/infozip/zlib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cdrom.com/pub/infozip/zlib/

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --shared

.include "../../mk/bsd.prefs.mk"

#.if ${OPSYS} == "SunOS"
#.if !make(fake-pkg)
#CC=		cc
#.endif
#.endif

.if exists(/usr/lib/libz.a)
IGNORE=		"is part of your NetBSD distribution"
.endif

post-extract:
	@cd ${WRKDIR} && ${MKDIR} static && ${PAX} -rw ${DISTNAME} static

post-patch:
	@${MAKE} do-patch WRKSRC=${WRKDIR}/static/${DISTNAME}

post-configure:
	@${MAKE} do-configure WRKSRC=${WRKDIR}/static/${DISTNAME} \
	CONFIGURE_ARGS="`${ECHO} ${CONFIGURE_ARGS} | ${SED} -e 's/--shared//'`"

post-build:
	@${MAKE} do-build WRKSRC=${WRKDIR}/static/${DISTNAME}

post-install:
	${INSTALL_DATA} ${WRKDIR}/static/${DISTNAME}/libz.a ${PREFIX}/lib
	cd ${PREFIX}/lib && ranlib libz.a

.include "../../mk/bsd.pkg.mk"
