# $NetBSD: Makefile,v 1.1.1.1 2005/01/24 19:40:59 jschauma Exp $
#

DISTNAME=		nspr-4.3
WRKSRC=			${WRKDIR}/${DISTNAME}/mozilla/nsprpub
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_MOZILLA:=../../nspr/releases/v4.3/src/}

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		ftp://ftp.mozilla.org/pub/mozilla.org/nspr/releases/v4.3/README
COMMENT=		Platform-neutral API for system level and libc like functions

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/nspr
	(cd ${WRKSRC}/dist/include && ${PAX} -Lrwvpe . ${PREFIX}/include/ )
	(cd ${WRKSRC}/dist/lib && ${PAX} -Lrwvpe . ${PREFIX}/lib/ )
	${INSTALL_SCRIPT} ${WRKSRC}/config/nspr-config ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
