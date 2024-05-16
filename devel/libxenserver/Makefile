# $NetBSD: Makefile,v 1.41 2024/05/16 06:14:46 wiz Exp $
#

VERSION=	6.2.0
DISTNAME=	XenServer-${VERSION}-SDK
PKGNAME=	libxenserver-${VERSION}
PKGREVISION=	32
CATEGORIES=	devel
MASTER_SITES=	http://downloadns.citrix.com.edgesuite.net/7289/

MAINTAINER=	sborrill@NetBSD.org
HOMEPAGE=	http://community.citrix.com/cdn/xs/sdks/
COMMENT=	Citrix XenServer SDK for C
LICENSE=	2-clause-bsd

EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}/XenServer-SDK/libxenserver/src
MAJOR=		2
MINOR=		0
BUILD_TARGET=	libxenserver.so
USE_TOOLS+=	gmake pax

PLIST_SUBST+=	MAJOR=${MAJOR:Q} MINOR=${MINOR:Q}

INSTALLATION_DIRS=	include/xen/api
INSTALLATION_DIRS+=	share/examples/libxenserver lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/libxenserver.so.${MAJOR}.${MINOR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libxenserver.so ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/include/xen/api && pax -rw *.h ${DESTDIR}${PREFIX}/include/xen/api
	cd ${WRKSRC}/test &&  pax -rw *.c ${DESTDIR}${PREFIX}/share/examples/libxenserver

.include "../../mk/bsd.prefs.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
